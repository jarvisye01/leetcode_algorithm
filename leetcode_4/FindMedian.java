package leetcode_4;

public class FindMedian {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len_1 = nums1.length;
        int len_2 = nums2.length;
        int half_len = (len_1 + len_2) / 2;
        int i = 0;
        int j = 0;
        int last_num = 0;
        int current_num = 0;
        int count = 0;
        while(i < len_1 && j < len_2) {
            last_num = current_num;
            if(nums1[i] <= nums2[j]) {
                ++i;
                current_num = nums1[i - 1];
            }
            else {
                ++j;
                current_num = nums2[j - 1];
            }
            ++count;
            if((len_1 + len_2) % 2 != 0 && count == half_len + 1) {
                return current_num;
            }
            else if((len_1 + len_2) % 2 == 0 && count == half_len + 1) {
                return ((last_num + current_num) * 1.0) / 2;
            }
        }
        while(i < len_1) {
            last_num = current_num;
            current_num = nums1[i++];
            ++count;
            if((len_1 + len_2) % 2 != 0 && count == half_len + 1) {
                return current_num;
            }
            else if((len_1 + len_2) % 2 == 0 && count == half_len + 1) {
                return ((last_num + current_num) * 1.0) / 2;
            }
        }
        while(j < len_2) {
            last_num = current_num;
            current_num = nums2[j++];
            ++count;
            if((len_1 + len_2) % 2 != 0 && count == half_len + 1) {
                return current_num;
            }
            else if((len_1 + len_2) % 2 == 0 && count == half_len + 1) {
                return ((last_num + current_num) * 1.0) / 2;
            }
        }
        return 0;
    }
    public static void main(String [] args) {
        int[] nums1 = {1, 3};
        int[] nums2 = {2, 3, 4, 6, 7, 8};
        double result = findMedianSortedArrays(nums1, nums2);
        System.out.println(result);
    }
}
