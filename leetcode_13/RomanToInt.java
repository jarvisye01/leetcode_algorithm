package leetcode_13;

public class RomanToInt {
    public static int romanToInt(String s) {
        if(s.length() == 0) {
            return 0;
        }

        int result = 0;
        int i = 0;
        int s_len = s.length();

        while(i < s_len) {
            if(s.charAt(i) == 'I' || s.charAt(i) == 'X' || s.charAt(i) == 'C') {
                if(i < s_len && s.charAt(i) == 'I') {
                    if(i + 1 < s_len) {
                        if(s.charAt(i + 1) == 'V') {
                            result += 4;
                            i = i + 2;
                        }
                        else if(s.charAt(i + 1) == 'X') {
                            result += 9;
                            i = i + 2;
                        }
                        else {
                            result += 1;
                            ++i;
                        }
                    }
                    else {
                        result += 1;
                        ++i;
                    }
                }
                if(i < s_len && s.charAt(i) == 'X') {
                    if(i + 1 < s_len) {
                        if(s.charAt(i + 1) == 'L') {
                            result += 40;
                            i = i + 2;
                        }
                        else if(s.charAt(i + 1) == 'C') {
                            result += 90;
                            i = i + 2;
                        }
                        else {
                            result += 10;
                            ++i;
                        }
                    }
                    else {
                        result += 10;
                        ++i;
                    }
                }
                if(i < s_len && s.charAt(i) == 'C') {
                    if(i + 1 < s_len) {
                        if(s.charAt(i + 1) == 'D') {
                            result += 400;
                            i = i + 2;
                        }
                        else if(s.charAt(i + 1) == 'M') {
                            result += 900;
                            i = i + 2;
                        }
                        else {
                            result += 100;
                            ++i;
                        }
                    }
                    else {
                        result += 100;
                        ++i;
                    }
                }
            }
            else {
                if(s.charAt(i) == 'V') {
                    result += 5;
                }
                if(s.charAt(i) == 'L') {
                    result += 50;
                }
                if(s.charAt(i) == 'D') {
                    result += 500;
                }
                if(s.charAt(i) == 'M') {
                    result += 1000;
                }
                ++i;
            }
        }
        return result;
    }

    public static void main(String [] args) {
        System.out.println(romanToInt("IX"));
    }
}
