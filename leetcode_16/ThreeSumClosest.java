package leetcode_16;

import java.util.Arrays;

public class ThreeSumClosest {
    public static int threeSumClosest(int[] nums, int target) {
        int nums_len = nums.length;
        if(nums_len < 3) {
            return 0;
        }
        Arrays.sort(nums);
        int temp_closest = nums[0] + nums[1] + nums[2];
        for(int i = 0 ; i < nums_len - 2 ; ++i) {
            int Left = i + 1;
            int Right = nums_len - 1;
            while(Left < Right) {
                int temp_num = nums[i] + nums[Left] + nums[Right];

                if(temp_num < target) {
                    ++Left;
                }
                else if(temp_num == target) {
                    return target;
                }
                else {
                    --Right;
                }
//                temp_closest = Math.min(temp_closest, Math.abs(temp_num - target));
                temp_closest = Math.abs(temp_closest - target) < Math.abs(temp_num - target) ? temp_closest : temp_num;
            }

        }

        return temp_closest;
    }
    public static void main(String [] agrs) {
        System.out.println();
    }
}
