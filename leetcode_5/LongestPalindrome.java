package leetcode_5;

import java.util.HashMap;
import java.util.Map;

public class LongestPalindrome {
    public static boolean test(String s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            if(s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }
        return true;
    }
//    public static String longestPalindrome(String s) {
//        暴力法O(n^3)
//        int len = s.length();
//        Map<Character, Integer> char_location = new HashMap<>();
//        int[] next_char = new int[len];
//        for(int i = len - 1 ; i >= 0 ; --i) {
//            if(null == char_location.get(s.charAt(i))) {
//                next_char[i] = -1;
//            }
//            else {
//                next_char[i] = char_location.get(s.charAt(i));
//            }
//            char_location.put(s.charAt(i), i);
//        }
//        int i = 0;
//        int begin = -1;
//        int end = -1;
//        int max_len = 0;
//        while(i < len) {
//            int temp = i;
//            while(temp != -1) {
//                if(test(s.substring(i, temp + 1))) {
//                    if(temp - i + 1 >= max_len) {
//                        max_len = temp - i + 1;
//                        begin = i;
//                        end = temp;
//                    }
//                }
//                temp = next_char[temp];
//            }
//            ++i;
//        }
//        return end == -1 ? "" : s.substring(begin, end + 1);
//    }

    public static String longestPalindrome(String s) {

        if(null == s) {
            return null;
        }
        if(s.length() == 1 || s.length() == 0) {
            return s;
        }

        int s_length = s.length();
        int[][] table = new int[s_length][s_length];
        int max_length = 0;
        int begin = 0;
        int end = 0;

        for(int i = 0 ; i < s_length ; ++i) {
            table[i][i] = 1;
        }
        for(int i = 0 ; i < s_length - 1 ; ++i) {
            if(s.charAt(i) == s.charAt(i + 1)) {
                table[i][i + 1] = 1;
                if(2 >= max_length) {
                    max_length = 2;
                    begin = i;
                    end = i + 2;
                }
            }
            else {
                table[i][i + 1] = 0;
            }
        }

        for(int p_length = 3; p_length <= s_length ; ++p_length) {
            for(int i = 0 ; i <= s_length - p_length ; ++i) {
                if(s.charAt(i) == s.charAt(i + p_length - 1)) {
                    table[i][i + p_length - 1] = table[i + 1][i + p_length - 2];
                    if(table[i][i + p_length - 1] == 1 && p_length >= max_length) {
                        max_length = p_length;
                        begin = i;
                        end = i + p_length;
                    }
                }
                else {
                    table[i][i + p_length - 1] = 0;
                }
            }
        }

        return end != 0 ? s.substring(begin, end) : s.substring(s_length - 1);

    }

    public static void main(String [] args) {
        String s = longestPalindrome("ca");
        System.out.println(s);
    }
}
