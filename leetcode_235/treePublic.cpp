#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        
        TreeNode *left, *right;
        left = lowestCommonAncestor(root->left, p, q);
        right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) return root;
        else if (left != nullptr) return left;
        else if (right != nullptr) return right;
        
        return nullptr;
    }
};

int main(int argc, char **argv) {
    Solution s;

    TreeNode r1(1);
    TreeNode r2(2);
    TreeNode r3(3);
    TreeNode r4(4);
    r1.left = &r2;
    r1.right = &r3;
    r2.left = &r4;

    auto node = s.lowestCommonAncestor(&r1, &r4, &r3);
    std::cout << node->val << std::endl;
    return 0;
}