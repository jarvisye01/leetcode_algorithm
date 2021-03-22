#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (nullptr == root) 
            return vector<int>();
        vector<int> ret;
        queue<TreeNode*> q;
        q.push(root);
        int sz;
        while ((sz = q.size()) > 0) {
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                if (node->left != nullptr) 
                    q.push(node->left);
                if (node->right != nullptr) 
                    q.push(node->right);
                if (i == sz - 1)
                    ret.push_back(node->val);
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    using std::cout;
    using std::endl;

    TreeNode r1(1);
    TreeNode r2(2);
    TreeNode r3(3);
    TreeNode r4(4);
    TreeNode r5(5);
    TreeNode r6(6);

    r1.left = &r2;
    r2.left = &r3;
    r2.right = &r4;
    r4.left = &r5;
    r5.right = &r6;

    Solution s;
    vector<int> ret = s.rightSideView(&r1);
    for (auto x: ret) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}