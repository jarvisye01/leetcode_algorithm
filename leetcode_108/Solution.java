package leetcode_108;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) {
        val = x;
    }
}

public class Solution {

    public static TreeNode generate(int[] nums, int lo, int hi) {
        if (hi < lo) {
            return null;
        }
        int mid = lo + (hi - lo) / 2;
        TreeNode r = new TreeNode(nums[mid]);
        r.left = generate(nums, lo, mid - 1);
        r.right = generate(nums, mid + 1, hi);
        return r;
    }

    public static TreeNode sortedArrayToBST(int[] nums) {
        return generate(nums, 0, nums.length - 1);
    }
}
