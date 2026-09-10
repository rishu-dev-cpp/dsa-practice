/*// DP top - bottom
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        Integer[][] dp = new Integer[n][n + 1];
        return help(0, -1, nums, dp);
    }
    private int help(int idx, int prevIdx, int[] nums, Integer[][] dp) {
        if (idx == nums.length)
            return 0;

        if (dp[idx][prevIdx + 1] != null)
            return dp[idx][prevIdx + 1];

        // prevIdx ko unchanged rakho kyunki element skip kiya hai
        int notake = help(idx + 1, prevIdx, nums, dp);

        int take = 0;
        if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            take = 1 + help(idx + 1, idx, nums, dp);
        }
        return dp[idx][prevIdx + 1] = Math.max(take, notake);
    }
}
*/
/*
// DP bottom - top
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n + 1][n + 1]; // +1 for offset

        // Base case: idx == n already 0 in Java

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--) {
                
                // 1. Not Take
                int notake = dp[idx + 1][prevIdx + 1];

                // 2. Take
                int take = 0;
                if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
                    take = 1 + dp[idx + 1][idx + 1]; // prevIdx update ho gaya 'idx'
                }

                dp[idx][prevIdx + 1] = Math.max(take, notake);
            }
        }

        return dp[0][-1 + 1]; // Answer at start state
    }
}
*/
// Tabulation
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int maxLis = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = Math.max(dp[i], 1 + dp[j]);
                }
            }
            maxLis = Math.max(maxLis, dp[i]);
        }

        return maxLis;
    }
}





