#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void kthSamllestAux(TreeNode* node, int k, int *step, int *data, bool *res) {
        if (nullptr == node) return;
        kthSamllestAux(node->left, k, step, data, res);
        if (*step > k) return;
        (*step)++;
        if (*step == k) {
            *data = node->val;
            *res = true;
            return;
        }
        kthSamllestAux(node->right, k, step, data, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int data = -1, step = 0;
        bool res = false;
        kthSamllestAux(root, k, &step, &data, &res);
        // res => exist?
        return data;
    }
};

int main(int argc, char **argv) {
    Solution s;
    TreeNode r1(5);
    TreeNode r2(3);
    TreeNode r3(6);
    TreeNode r4(4);
    TreeNode r5(8);
    r3.left = &r4;
    r3.right = &r5;
    r4.left = &r2;
    r4.right = &r1;

    for (int i = 0; i < 5; i++) {
        std::cout << i + 1 << " => " << s.kthSmallest(&r3, i + 1) << std::endl;
    }
    return 0;
}