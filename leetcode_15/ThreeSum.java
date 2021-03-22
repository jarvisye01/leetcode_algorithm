package leetcode_15;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {
    public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> sums = new ArrayList<>();
        int nums_len = nums.length;
        if(nums == null || nums_len < 3) {
            return sums;
        }

        Arrays.sort(nums);
        for(int i = 0 ; i < nums_len ; ++i) {
            if(nums[i] > 0) {
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int Left = i + 1;
            int Right = nums_len - 1;
            while(Left < Right) {
                if(nums[i] + nums[Left] + nums[Right] == 0) {
                    sums.add(Arrays.asList(nums[i], nums[Left], nums[Right]));
                    while(Left < Right && nums[Left] == nums[Left + 1]) {
                        ++Left;
                    }
                    while(Left < Right && nums[Right] == nums[Right - 1]) {
                        --Right;
                    }
                    ++Left;
                    --Right;
                }
                else if(nums[i] + nums[Left] + nums[Right] < 0) {
                    ++Left;
                }
                else if(nums[i] + nums[Left] + nums[Right] > 0) {
                    --Right;
                }
            }

        }

        return sums;
    }
    public static void main(String [] args) {
        System.out.println(threeSum(new int[]{-1,0,1,2,-1,-4}));
    }
}
