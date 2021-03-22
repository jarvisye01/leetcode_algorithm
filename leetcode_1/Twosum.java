package leetcode_1;

import java.util.*;

public class Twosum {

    public static int[] solute_func(int[] nums, int target) {
        Map<Integer, Integer> nums_map = new HashMap<Integer, Integer>();
        for(int i = 0 ; i < nums.length ; ++i) {
            nums_map.put(nums[i], i);
        }
        for(int i = 0 ; i < nums.length ; ++i) {
            if(nums_map.keySet().contains(target - nums[i]) && nums_map.get(target - nums[i]) != i ) {
                return new int[]{i, nums_map.get(target - nums[i])};
            }
        }
        return null;
    }

    public static void main(String [] args) {
        int[] nums = new int[]{3,2,4};
        int target = 6;
        int[] solution = solute_func(nums, target);
        System.out.println(solution[0]);
        System.out.println(solution[1]);
    }
}
