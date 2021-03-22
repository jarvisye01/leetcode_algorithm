#include <iostream>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
    bool isLeaf(TreeNode *node)
    {
        if (node == NULL) return false;
        return node->left == NULL && node->right == NULL;
    }

    void sumAux(TreeNode *node, bool left, int& ret)
    {
        if (node == NULL) return;
        if (isLeaf(node) && left) 
        {
            ret += node->val;
            return;
        }
        sumAux(node->left, true, ret);
        sumAux(node->right, false, ret);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int ret = 0;
        sumAux(root, false, ret);
        return ret;
    }
};

int main(int argc, char **argv)
{
    TreeNode r1(3);
    TreeNode r2(9);
    TreeNode r3(20);
    TreeNode r4(15);
    TreeNode r5(17);
    r1.left = &r2, r1.right = &r3;
    r3.left = &r4, r3.right = &r5;

    Solution s;
    auto ret = s.sumOfLeftLeaves(&r1);
    std::cout << ret << std::endl;
}