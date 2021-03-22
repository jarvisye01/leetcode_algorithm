package leetcode_14;

public class LongestCommonPrefix {
    public static String get_common_str(String s1, String s2) {
        int s1_len = s1.length();
        int s2_len = s2.length();
        int i = 0;
        while(i < s1.length() && i < s2.length()) {
            if(s1.charAt(i) != s2.charAt(i)) {
                return s1.substring(0, i);
            }
            ++i;
        }
        if(i == s1_len)  {
            return s1;
        }
        if(i == s2_len) {
            return s2;
        }
        return "";
    }
    public static String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) {
            return "";
        }
        String str_common = strs[0];
        int strs_len = strs.length;

        for(int i = 0 ; i < strs_len ; ++i) {
            str_common = get_common_str(str_common, strs[i]);
            if(str_common.length() ==0) {
                return "";
            }
        }
        return str_common;
    }
    public static void main(String [] args) {
//        System.out.println(longestCommonPrefix());
    }
}
