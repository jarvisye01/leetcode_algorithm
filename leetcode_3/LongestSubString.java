package leetcode_3;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class LongestSubString {
//    除此解法
//    public static int lengthOfLongestSubstring(String s) {
//        int max_length = 0;
//        Map<Character, Integer> charMap = new HashMap<>();
//        int i = 0;
//        while(i <= s.length() - 1) {
//            charMap.clear();
//            int j = i;
//            for( ; j <= s.length() - 1 ; ++j) {
//                if(!charMap.containsKey(s.charAt(j))){
//                    charMap.put(s.charAt(j), j);
//                    max_length = max_length < charMap.size() ? charMap.size() : max_length;
//                }
//                else {
//                    i = charMap.get(s.charAt(j)) + 1;
//                    break;
//                }
//            }
//            if(j == s.length()) {
//                break;
//            }
//        }
//        return max_length;
//    }
//    滑动窗口
//
//    优化滑动窗口
    public static int lengthOfLongestSubstring(String s) {
        int n = s.length();
        Map<Character, Integer> characterIntegerMap = new HashMap<>();
        int max_length = 0;

        for(int i = 0, j = 0 ; j < n ; ++j) {
            if(characterIntegerMap.containsKey(s.charAt(j))) {
                i = Math.max(characterIntegerMap.get(s.charAt(j)), i);
            }

            max_length = Math.max(max_length, j - i + 1);
            characterIntegerMap.put(s.charAt(j), j + 1);
        }
        return max_length;
    }
    public static void main(String [] args) {
        String s = "bbbbb";
        int test_num = lengthOfLongestSubstring(s);
        System.out.println(test_num);
    }
}
