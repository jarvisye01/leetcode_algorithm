package leetcode_18;

import java.util.*;

public class FourSum {
    public static List<List<Integer>> fourSum(int[] nums, int target) {
        int nums_len = nums.length;
        List<List<Integer>> result_collection = new ArrayList<>();

        if(nums_len < 4) {
            return result_collection;
        }

//      排序
        Arrays.sort(nums);

        for(int i = 0 ; i < nums_len - 3 ; ++i) {
            int Left = i + 1;
            int Right = nums_len - 1;
            while(Left < Right - 1) {
                int temp_sum = nums[i] + nums[Left] + nums[Right];
                int four_num = target - temp_sum;
                if(four_num >= nums[Left] && four_num <= nums[Right]) {
                    for(int j = Left + 1 ; j < Right ; ++j) {
                        if(four_num == nums[j]) {
                            result_collection.add(Arrays.asList(nums[i], nums[Left], nums[j], nums[Right]));
                        }
                    }
                    while(Left < Right - 1 && nums[Left] == nums[Left + 1]) {
                        ++Left;
                    }
                    while(Left < Right - 1 && nums[Right] == nums[Right - 1]) {
                        --Right;
                    }
                }
                if(Math.abs(four_num - (nums[Left + 1] - nums[Left])) <= Math.abs(four_num - nums[Right - 1])) {
                    ++Left;
                }
                else {
                    --Right;
                }
            }
        }

        return result_collection;
    }

    public static void main(String [] args) {
        int[] test = new int[]{1,0,-1,0,-2,2};
        System.out.println(fourSum(test, 0));
    }

}
