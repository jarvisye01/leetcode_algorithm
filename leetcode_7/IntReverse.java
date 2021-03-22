package leetcode_7;

import java.util.ArrayList;
import java.util.List;

public class IntReverse {

    public static int reverse(int x) {
        boolean sign_flag = x < 0;
        int result = 0;
        int temp_num = x < 0 ? -x : x;
        while(temp_num > 0) {
//            在比较时候的技巧，如何让result不超过最大值
            if(result <= (Integer.MAX_VALUE - temp_num % 10) / 10) {
                result = result * 10 + temp_num % 10;
            }
            else {
                return 0;
            }
            temp_num /= 10;
        }
        return sign_flag ? -result : result;
    }

    public static int myReverse(int x) {
        boolean sign_flag = x < 0;
        int temp_num = x < 0 ? -x : x;
        String num_string = new String(Integer.toString(temp_num));

        long temp = Integer.parseInt(new StringBuffer(num_string).reverse().toString());

        if(temp <= Integer.MAX_VALUE) {
            return sign_flag ? -(int)temp : (int)temp;
        }

        return 0;
    }

    public static void main(String [] args) {
        System.out.println(reverse(1534236469));
        System.out.println(Integer.MAX_VALUE);
    }
}
