package leetcode_8;

import java.util.HashMap;
import java.util.Map;

public class MyAtoi {
    public static int myAtoi(String str) {
        if(str == "" || null == str) {
            return 0;
        }
        String num_string = str.trim();
        if(num_string == "" || null == num_string) {
            return 0;
        }
        Map<Character, Integer> char_int = new HashMap<>();
        for(int i = 0 ; i < 10 ; ++i) {
            char_int.put((char)(i + '0'), i);
        }
        boolean sign_flag = false;
        char first_char = num_string.charAt(0);
        int result = 0;

        if(first_char == '-' || first_char == '+' || char_int.containsKey(first_char)) {
            if(first_char == '-' || first_char == '+') {
                sign_flag = first_char == '-' ? true : false;
                num_string = num_string.substring(1);
            }
            int num_len = num_string.length();
            if(num_len == 0 ) {
                return 0;
            }

            int i = 0;
            while(char_int.containsKey(num_string.charAt(i))) {
                if(result <= (Integer.MAX_VALUE - char_int.get(num_string.charAt(i))) / 10) {
                    result = result * 10 + char_int.get(num_string.charAt(i));
                }
                else {
                    return sign_flag ? Integer.MIN_VALUE: Integer.MAX_VALUE;
                }
                ++i;
                if(i == num_len) {
                    break;
                }
            }
        }
        else {
            return 0;
        }

        return sign_flag ? -result : result;
    }
    public static void main(String [] args) {
        System.out.println(myAtoi(""));
    }

}
