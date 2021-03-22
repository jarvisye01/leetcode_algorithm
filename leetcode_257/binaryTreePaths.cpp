#include <iostream>
#include <vector>

using std::vector;
using std::string;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool is_leaf(TreeNode *node) { return node->left == nullptr && node->right == nullptr; }
public:
    void paths_aux(TreeNode *node, const string& path, vector<string>& ret) {
        if (node == nullptr) return;
        if (is_leaf(node)) {
            ret.push_back(path + std::to_string(node->val));
            return;
        }

        if (node->left != nullptr) paths_aux(node->left, path + std::to_string(node->val) + "->", ret);
        if (node->right != nullptr) paths_aux(node->right, path + std::to_string(node->val) + "->", ret);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        paths_aux(root, "", ret);
        return ret;
    }
};

int main(int argc, char **argv) {
    TreeNode r1(1);
    TreeNode r2(2);
    TreeNode r3(3);
    TreeNode r4(5);
    r1.left = &r2;
    r1.right = &r3;
    r2.right = &r4;
    
    Solution s;
    vector<string> ret = s.binaryTreePaths(&r1);
    for (auto s: ret) std::cout << s << " ";
    std::cout << std::endl;
    return 0;
}