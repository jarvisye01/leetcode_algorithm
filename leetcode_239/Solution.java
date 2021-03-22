package leetcode_239;

import java.util.TreeMap;

public class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (k <= 0) return null;
        int[] ret = new int[nums.length - k + 1];

        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < k; i++)
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);

        for (int i = 0; i < ret.length - 1; i++) {
            ret[i] = map.lastKey();
            int count;

            // delete first
            if ((count = map.get(nums[i])) == 1)
                map.remove(nums[i]);
            else
                map.put(nums[i], count - 1);

            // add last
            map.put(nums[i + k], map.getOrDefault(nums[i + k], 0) + 1);
        }

        ret[ret.length - 1] = map.lastKey();
        return ret;
    }

    public static void main(String[] args) {
        int nums[] = new int[]{1,3,-1,-3,5,3,6,7}, k = 3;
        Solution s = new Solution();
        int[] ret = s.maxSlidingWindow(nums, k);

        for (int x: ret)
            System.out.printf("%d ", x);
        System.out.println();
    }
}
