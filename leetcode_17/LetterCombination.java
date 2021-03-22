package leetcode_17;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LetterCombination {
    public ArrayList<String> get_charwithnum(int num) {
        if(num == 2) {
            return new ArrayList<String>(Arrays.asList("a", "b", "c"));
        }
        if(num == 3) {
            return new ArrayList<String>(Arrays.asList("d", "e", "f"));
        }
        if(num == 4) {
            return new ArrayList<String>(Arrays.asList("g", "h", "i"));
        }
        if(num == 5) {
            return new ArrayList<String>(Arrays.asList("j", "k", "l"));
        }
        if(num == 6) {
            return new ArrayList<String>(Arrays.asList("m", "n", "o"));
        }
        if(num == 7) {
            return new ArrayList<String>(Arrays.asList("p", "q", "r", "s"));
        }
        if(num == 8) {
            return new ArrayList<String>(Arrays.asList("t", "u", "v"));
        }
        if(num == 9) {
            return new ArrayList<String>(Arrays.asList("w", "x", "y", "z"));
        }
        return null;
    }
    public List<String> letterCombinations(String digits) {
        List<String> strings = new ArrayList<>();
        if(digits.length() == 0) {
            return strings;
        }

        List<String> num_char = get_charwithnum(Character.getNumericValue(digits.charAt(0)));
        for(String string: num_char) {
            strings.add(string);
        }

        for(int i = 1 ; i < digits.length() ; ++i) {
            num_char = get_charwithnum(Character.getNumericValue(digits.charAt(i)));
            List<String> temp_strings = new ArrayList<>();
            for(String string_1: strings) {
                for(String string_2: num_char) {
                    temp_strings.add(new String(string_1 + string_2));
                }
            }
            strings = temp_strings;
        }

        return strings;
    }
    public static void main(String [] args) {
        System.out.println(new LetterCombination().letterCombinations("23"));
    }
}
