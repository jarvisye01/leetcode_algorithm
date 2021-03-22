package leetcode_11;

public class MaxArea {
//    双指针解法
    public static int maxArea(int[] height) {
        int max_water = 0;
        int i = 0;
        int j = height.length - 1;
        while(i < j) {
            max_water = Math.max(max_water, (j - i) * Math.min(height[i], height[j]));
            if(height[i] < height[j]) {
                ++i;
            }
            else {
                --j;
            }
        }
        return max_water;
    }
    public static void main(String [] args) {
        int[] test = new int[]{1,8,6,2,5,4,8,3,7};
        int max_water = maxArea(test);
        System.out.println(max_water);
    }
}
