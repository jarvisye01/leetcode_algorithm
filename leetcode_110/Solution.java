package leetcode_110;

import java.util.HashMap;
import java.util.Map;

class TreeNode {
    int val;
    int height;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) {
        val = x;
        height = -1;
    }
}

public class Solution {

    static Map<TreeNode, Integer> depth = new HashMap<>();

    public static int mydepth(TreeNode r) {
        if (null == r) {
            return 0;
        }
        if (r.height != -1) {
            return r.height;
        }
        r.height = Math.max(mydepth(r.left), mydepth(r.right)) + 1;
        return r.height;
    }

    public static int depth(TreeNode r) {
        if (null == r) {
            return 0;
        }
        if (depth.containsKey(r)) {
            return depth.get(r);
        }
        int ld = depth(r.left);
        int rd = depth(r.right);
        return Math.max(ld, rd) + 1;
    }

    public static boolean judge(TreeNode r) {
        if (null == r) {
            return true;
        }
        if (judge(r.left) && judge(r.right)) {
            int ld = mydepth(r.left);
            int rd = mydepth(r.right);
            return Math.abs(ld - rd) <= 1;
        }
        return false;
    }

    public static boolean isBalanced(TreeNode root) {
        return judge(root);
    }

    public static void main(String[] args) {

    }
}
