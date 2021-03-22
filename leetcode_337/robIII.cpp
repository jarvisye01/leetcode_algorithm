#include <iostream>
#include <unordered_map>

using std::unordered_map; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Hash {
    size_t operator() (TreeNode *node) const {
        return size_t(node);
    }
};

class Solution {
    int robAuxII(TreeNode *node, unordered_map<TreeNode*, int, Hash>& map) {
        if (nullptr == node) return 0;
        if (map.find(node) != map.end()) return map.find(node)->second;

        int ret1 = 0, ret2 = 0, ret;
        // rob the current node
        if (nullptr != node->left) ret1 += robAuxII(node->left->left, map) + robAuxII(node->left->right, map);
        if (nullptr != node->right) ret1 += robAuxII(node->right->left, map) + robAuxII(node->right->right, map);
        ret1 += node->val;
        
        // don`t rob the current node
        ret2 = robAuxII(node->left, map) + robAuxII(node->right, map);

        ret = std::max(ret1, ret2);
        map.insert(std::make_pair(node, ret));
        return ret;
    }

public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int, Hash> m;
        return robAuxII(root, m);
    }
};

int main(int argc, char **argv) {
    TreeNode r1(3);
    TreeNode r2(4);
    TreeNode r3(5);
    TreeNode r4(1);
    TreeNode r5(3);
    TreeNode r6(1);
    r1.left = &r2;
    r1.right = &r3;
    r2.left = &r4;
    r2.right = &r5;
    r3.right = &r6;

    Solution s;
    int ret = s.rob(&r1);
    std::cout << "ret = " << ret << std::endl;

    return 0;
}