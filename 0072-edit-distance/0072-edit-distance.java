class Solution {
    private int[][] dp;

    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        
        dp = new int[m + 1][n + 1];
        for (int[] it : dp) {
            Arrays.fill(it, -1);
        }

        return solve(0, 0, word1, word2);
    }

    private int solve(int i, int j, String word1, String word2) {
        // BASE CASES: Agar ek string khatam ho jaye, to dusri string ke bache chars insert/delete karne padenge
        if (i == word1.length()) return word2.length() - j; // Insert remaining word2 chars
        if (j == word2.length()) return word1.length() - i; // Delete remaining word1 chars

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // MATCH CASE
        if (word1.charAt(i) == word2.charAt(j)) {
            return dp[i][j] = solve(i + 1, j + 1, word1, word2);
        }

        // MISMATCH CASE: Try all 3 operations
        int insert  = solve(i, j + 1, word1, word2);
        int delete  = solve(i + 1, j, word1, word2);
        int replace = solve(i + 1, j + 1, word1, word2);

        return dp[i][j] = 1 + Math.min(insert, Math.min(delete, replace));
    }
}