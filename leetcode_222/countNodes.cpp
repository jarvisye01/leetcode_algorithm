#include <iostream>
#include <unordered_map>

using std::unordered_map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

struct Hash {
    size_t operator() (TreeNode *node) const {
        return size_t(node);
    }
};

class Solution {
    unordered_map<TreeNode*, int, Hash> m;
    int ret = 0;
public:
    int countNodesAux(TreeNode* root) {
        if (nullptr == root) return 0;
        int count;
        if (m.find(root) !=  m.end()) { count = m.find(root)->second; }
        else {
            count = 1 + countNodesAux(root->left) + countNodesAux(root->right);
            m.insert(std::pair<TreeNode*, int>(root, count));
        }
        return count;
    }

    void countNodesAux1(TreeNode* root) {
        if (nullptr == root) return;
        countNodesAux1(root->left);
        ret++;
        countNodesAux1(root->right);
    }

    int countNodes(TreeNode* root) {
        // return countNodesAux(root);
        countNodesAux1(root);
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    TreeNode r1(1);
    TreeNode r2(3);
    r1.left = &r2;
    std::cout << s.countNodes(&r1) << std::endl;
    return 0;
}