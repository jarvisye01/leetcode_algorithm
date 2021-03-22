package leetcode_10;

public class IsMatch {
    public static boolean judge_func(int x, int y, int s_len, int p_len, int[][] dp) {
        if(x >= 0 && x <= s_len && y >= 0 && y <= p_len) {
            if(dp[x][y] == 1) {
                return true;
            }
        }
        return false;
    }

    public static boolean isMatch(String s, String p) {
        int s_len = s.length();
        int p_len = p.length();

//        扩大数组范围，解决空串之间的问题
        int[][] dp = new int[s_len + 1][p_len + 1];

        for(int i = 0 ; i <= s_len ; ++i) {
            for(int j = 0 ; j <= p_len ; ++j) {
                dp[i][j] = 0;
            }
        }

        for(int j = 0 ; j <= p_len ; ++j) {
            if(j == 0) {
                dp[0][j] = 1;
            }
            else {
                if(p.charAt(j - 1) == '*' && j - 2 >= 0 && judge_func(0, j - 2, s_len, p_len, dp)) {
                    dp[0][j] = 1;
                }
            }
        }

        if(s_len > 0 && p_len > 0) {
            for(int i = 1 ; i <= s_len ; ++i) {
                for(int j = 1 ; j <= p_len ; ++j) {
                    if(s.charAt(i - 1) == p.charAt(j - 1) || p.charAt(j - 1) == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    if(p.charAt(j - 1) == '*') {
                        if(s.charAt(i -1) != p.charAt(j - 2) || p.charAt(j - 2) != '.') {
                            dp[i][j] = dp[i][j - 2];
                        }
                        if(s.charAt(i -1) == p.charAt(j - 2) || p.charAt(j - 2) == '.') {
                            boolean judge = judge_func(i, j - 1, s_len, p_len, dp) ||
                                    judge_func(i, j - 2, s_len, p_len, dp) ||
                                    judge_func(i - 1, j, s_len, p_len, dp);
                            dp[i][j] = judge ? 1 : 0;
                        }
                    }
                }
            }
        }

        return dp[s_len][p_len] == 1 ? true : false;
    }

    public static void main(String [] args) {
        boolean test = isMatch("aa", "a*");
        if(test) {
            System.out.println("match");
        }
        else {
            System.out.println("no match");
        }
    }
}
