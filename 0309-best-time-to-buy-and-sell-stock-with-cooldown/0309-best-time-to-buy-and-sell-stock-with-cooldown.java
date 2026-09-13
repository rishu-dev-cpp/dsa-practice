// buy have two state 0 and 1
// when buy is 1 then we have to buy
// when buy is 0 then we have to sell
class Solution {
    int[][] dp;
    public int maxProfit(int[] prices) {
        int n = prices.length;
        dp = new int[n][2];
        for (int[] it : dp) {
            Arrays.fill(it, -1);
        }
        return help(0, 1, prices);
    }
    private int help(int i, int buy, int[] prices) {
        if (i >= prices.length) {
            return 0;
        }
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        if (buy == 1) {
            // Choice A: Buy today | Choice B: Skip today
            int buyToday = -prices[i] + help(i + 1, 0, prices);
            int skipToday = help(i + 1, 1, prices);
            return dp[i][buy] = Math.max(buyToday, skipToday);
        } else {
            // Choice A: Sell today (Jump i + 2 for Cooldown!) | Choice B: Skip today
            int sellToday = prices[i] + help(i + 2, 1, prices);
            int skipToday = help(i + 1, 0, prices);
            return dp[i][buy] = Math.max(sellToday, skipToday);
        }
    }
}
