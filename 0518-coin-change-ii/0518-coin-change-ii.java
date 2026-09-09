/*// recursion
class Solution {
    public int change(int amount, int[] coins) {
        return recur(0, coins, amount);
    }
    private int recur(int idx, int[] coins, int amount) {
        if (amount == 0)
            return 1;

        if (amount < 0 || idx == coins.length)
            return 0;

        int take = recur(idx, coins, amount - coins[idx]);
        int notTake = recur(idx + 1, coins, amount);

        return take + notTake;
    }
}
*/
// DP (Memoization)
class Solution {
    Integer dp[][];
    public int change(int amount, int[] coins) {
        dp = new Integer[coins.length][amount + 1];
        return recur(0, coins, amount);
    }
    private int recur(int idx, int[] coins, int amount) {
        if (amount == 0) {
            return 1;
        }
        if (amount < 0 || idx == coins.length) {
            return 0;
        }
        if (dp[idx][amount] != null) {
            return dp[idx][amount];
        }
        int take = recur(idx, coins, amount - coins[idx]);
        int notTake = recur(idx + 1, coins, amount);

        return dp[idx][amount] = take + notTake;
    }
}
