/*// recursion
class Solution {
    public int uniquePaths(int m, int n) {
        return help(m, n, 0, 0);
    }

    private int help(int m, int n, int r, int c) {
        int count = 0;
        if (r == m || c == n)
            return 0;
        if (r == m - 1 && c == n - 1)
            return 1;
        count += help(m, n, r + 1, c);
        count += help(m, n, r, c + 1);
        return count;
    }
}
*/
// DP bottom - up
/*
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (r == 0 && c == 0) {
                    dp[r][c] = 1;
                } else {
                    int up = (r > 0) ? dp[r - 1][c] : 0;
                    int left = (c > 0) ? dp[r][c - 1] : 0;
                    dp[r][c] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
}
*/
// DP top - down
class Solution {
    int[][] dp;

    public int uniquePaths(int m, int n) {
        dp = new int[m][n];
        for (int[] it : dp) {
            Arrays.fill(it, -1);
        }

        return help(m, n, 0, 0);
    }

    private int help(int m, int n, int r, int c) {
        int count = 0;
        if (r == m || c == n)
            return 0;
        if (r == m - 1 && c == n - 1)
            return 1;
        if (dp[r][c] != -1)
            return dp[r][c];

        count += help(m, n, r + 1, c);
        count += help(m, n, r, c + 1);

        return dp[r][c] = count;
    }
}

