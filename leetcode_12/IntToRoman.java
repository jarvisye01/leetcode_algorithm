package leetcode_12;

import java.util.HashMap;
import java.util.Map;

public class IntToRoman {
    public static String add_string(int n, String string) {
        String temp_string = "";
        for(int i = 0 ; i < n ; ++i) {
            temp_string  = temp_string + string;
        }
        return temp_string;
    }
    public static String intToRoman(int num) {
        Map<Integer, String> int_roman = new HashMap<>();
        int_roman.put(1, "I");
        int_roman.put(4, "IV");
        int_roman.put(5, "V");
        int_roman.put(9, "IX");
        int_roman.put(10, "X");
        int_roman.put(40, "XL");
        int_roman.put(50, "L");
        int_roman.put(90, "XC");
        int_roman.put(100, "C");
        int_roman.put(400, "CD");
        int_roman.put(500, "D");
        int_roman.put(900, "CM");
        int_roman.put(1000, "M");

        String roman_string = "";
        int[] divides = new int[]{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int i = 0;
        while(num > 0) {
            roman_string = roman_string + add_string(num / divides[i], int_roman.get(divides[i]));
            num = num - (num / divides[i]) * divides[i];
            ++i;
        }
        return roman_string;
    }

    public static void main(String [] args) {
        System.out.println(intToRoman(3999));
    }

}
