package leetcode_9;

public class IsPalindrome {
    public static boolean isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        if(x == 0) {
            return true;
        }

        String num_string = Integer.toString(x);

        int i = 0;
        int j = num_string.length() - 1;
        while(i <= j) {
            if(!(num_string.charAt(i++) == num_string.charAt(j--))) {
                return false;
            }
        }

        return true;

    }
    public static void main(String [] args) {

    }
}
