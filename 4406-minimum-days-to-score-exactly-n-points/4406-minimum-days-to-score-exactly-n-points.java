class Solution {
    int dp[];
    public int minDays(int n) {
        dp = new int[n + 1];
        Arrays.fill(dp, -1);

        return help(n) - 1;
    }
    private int help(int target){
        if(target == 0) {
            return 0;
        }
        if(dp[target] != -1) return dp[target];

        int minDays = (int) 1e9;
        
        for(int k = 1; ;k++){
            int points = k * (k + 1) / 2;
            if(points > target) break;

            int days = k + 1;

            int totalDays = days + help(target - points);

            minDays = Math.min(minDays, totalDays);
        }
        return dp[target] = minDays;
    }
}