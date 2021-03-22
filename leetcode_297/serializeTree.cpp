#include <iostream>
#include <string>
#include <deque>

using std::string;
using std::deque;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    // root != nullptr
    TreeNode *getLastNode(TreeNode *root) {
        deque<TreeNode*> queue;
        queue.push_back(root);

        TreeNode *lastNode = nullptr;

        while (queue.size() > 0) {
            int tsz = queue.size();
            bool isLastLevel = true;

            for (int i = 0; i < tsz; i++) {
                TreeNode *tmp = queue.front();
                queue.pop_front();

                if (nullptr != tmp->left) 
                    queue.push_back(tmp->left);
                if (nullptr != tmp->right)
                    queue.push_back(tmp->right);

                if (i == tsz - 1) 
                    lastNode = tmp;
            }
        }

        return lastNode;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (nullptr == root) return string("[]");

        string ret = "";
        deque<TreeNode*> queue;
        queue.push_back(root);
        bool processNull = true;
        TreeNode *lastNode = getLastNode(root);

        while (queue.size() > 0) {
            int tsz = queue.size();

            for (int i = 0; i < tsz; i++) {
                TreeNode *tmp = queue.front();
                queue.pop_front();

                if (nullptr == tmp) {
                    ret.append(string("null") + ",");
                    continue;
                }

                ret.append(std::to_string(tmp->val) + ",");
                if (processNull || nullptr != tmp->left) 
                    queue.push_back(tmp->left);
                if (processNull && (tmp->left == lastNode || tmp->right == lastNode)) 
                    processNull = !processNull;
                if (processNull || nullptr != tmp->right) 
                    queue.push_back(tmp->right);
            }
        }

        // delete last ', '
        ret.pop_back();

        return string("[" + ret + "]");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int sz, i = 1;;
        if ((sz = data.length()) < 3) return nullptr;

        TreeNode *root = nullptr;
        deque<TreeNode*> queue;
        int direct = 0, noRoot = 1;

        while (i < sz - 1) {
            // trim space
            while (i < sz - 1 && data[i] == ' ') 
                i++;
            
            if (data[i] == ',') {
                // process ,
                i++;
                continue;
            } else if ((data[i] >= '0' && data[i] <= '9' ) || data[i] == '-') {
                // process number
                int val = 0, flag = 1;
                // num < 0
                if (data[i] == '-') {
                    flag = -1;
                    i++;
                    // trim space
                    while (i < sz - 1 && data[i] == ' ') 
                        i++;
                }

                while (data[i] >= '0' && data[i] <= '9') {
                    val = val * 10 + static_cast<int>(data[i] - '0');
                    i++;
                }

                TreeNode *newNode = new TreeNode(val * flag);
                if (noRoot) {
                    root = newNode;
                    noRoot = 0;
                }
                else {
                    TreeNode *parent = queue.front();
                    if (!direct) {
                        // left
                        parent->left = newNode;
                    } else { 
                        // right
                        parent->right = newNode; 
                        queue.pop_front();
                    }
                    direct = (direct + 1) % 2;
                }
                queue.push_back(newNode);
            } else if (data[i] == 'n') {
                // process null
                i += 4;
                if (direct) 
                    queue.pop_front();
                direct = (direct + 1) % 2;
            }
        }

        return root;
    }
};

int main(int argc, char **argv) {
    TreeNode r1(1);
    TreeNode r2(2);
    TreeNode r3(3);
    TreeNode r4(4);
    TreeNode r5(5);
    TreeNode r6(6);
    r1.left = &r2;
    r1.right = &r3;
    r2.left = &r4;
    r2.right = &r5;
    r3.right = &r6;
    
    Codec encoder;
    string ret = encoder.serialize(&r1);
    std::cout << "serialize: " << ret << std::endl;

    Codec decoder;
    string data = "[4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]";
    TreeNode *root = decoder.deserialize(data);
    std::cout << "deserialize: " << decoder.serialize(root) << std::endl;
    return 0;
}