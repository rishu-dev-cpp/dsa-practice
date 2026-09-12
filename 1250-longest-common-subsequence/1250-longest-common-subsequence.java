class Solution {
    int[][] dp;
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();

        dp = new int[m + 1][n + 1];
        for(int[] it : dp) {
            Arrays.fill(it, -1);
        }
        return help(text1, text2, m - 1, n - 1);
    }
    private int help(String a, String b, int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if (a.charAt(i) == b.charAt(j)) {
            return 1 + help(a, b, i - 1, j - 1);
        }
        return dp[i][j] = Math.max(help(a, b, i, j - 1), help(a, b, i - 1, j));
    }
}
