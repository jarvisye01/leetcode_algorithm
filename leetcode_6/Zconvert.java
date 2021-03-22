package leetcode_6;

public class Zconvert {
    public static String convert(String s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        int s_length = s.length();
        char[] chars = new char[s.length()];

        int interval = (numRows - 1) * 2;
        int row_interval = 0;
        int char_nums = 0;

         for(int i = 0 ; i < numRows ; ++i) {
             int temp = i;
             while(temp < s_length) {
                 if(temp < s_length) {
                     chars[char_nums++] = s.charAt(temp);
                 }
                 if(temp + interval - row_interval != temp && temp + interval - row_interval != temp + interval && temp + interval - row_interval < s.length()) {
                     chars[char_nums++] = s.charAt(temp + interval - row_interval);
                 }
                 temp += interval;
             }
             row_interval += 2;
         }

        return new String(chars);

    }
    public static void main(String [] aegs) {
        System.out.println(convert("ABC", 2));
    }
}
