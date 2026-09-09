/*// recursion
class Solution {
    public int coinChange(int[] coins, int amount) {
        int ans = recur(coins, amount);
        return ans < (1e9) ? ans : -1;
    }
    private int recur(int[] coins, int amount) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return (int) 1e9;

        int minCoins = (int) 1e9;

        for (int coin : coins) {
            int result = recur(coins, amount - coin);
            minCoins = Math.min(minCoins, 1 + result);
        }
        return minCoins;
    }
}
*/
// DP (Memoization)
class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, -1);

        int ans = recur(coins, amount, dp);
        return ans < (1e9) ? ans : -1;
    }
    private int recur(int[] coins, int amount, int[] dp) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return (int) 1e9;
        }
        if (dp[amount] != -1) {
            return dp[amount];
        }
        int minCoins = (int) 1e9;

        for (int coin : coins) {
            int result = recur(coins, amount - coin, dp);
            minCoins = Math.min(minCoins, 1 + result);
        }
        return dp[amount] = minCoins;
    }
}