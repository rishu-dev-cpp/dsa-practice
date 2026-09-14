class Solution {
    private int[][] dp;
    private int totalsum;
    public int findTargetSumWays(int[] nums, int target) {
        totalsum = 0;
        for(int num : nums) totalsum += num;

        // Total sum can range from -totalSum (all -) to +totalSum (all +).
        // Total possible values = totalSum (negative) + 1 (zero) + totalSum (positive) = 2 * totalSum + 1
        dp =  new int[nums.length][2 * totalsum + 1];

        // Ways count CAN be 0 (valid DP answer), so we initialize with Integer.MIN_VALUE
        // instead of default 0 to distinguish uncalculated states from valid 0-ways states.
        for(int[] it : dp){
            Arrays.fill(it, Integer.MIN_VALUE);
        }

        return backtrack(0, 0, nums, target);
    }
    private int backtrack(int i, int total, int[] nums, int target) {
        if(i == nums.length) {
            return total == target ? 1 : 0;
        }
        int shiftedIndex = total + totalsum;

        if(dp[i][shiftedIndex] != Integer.MIN_VALUE){
            return dp[i][shiftedIndex];
        }

        // Choice (+): Add current num
        int add = backtrack(i + 1, total + nums[i], nums, target); 

        // Choice (-): Subtract current num
        int subtract = backtrack(i + 1, total - nums[i], nums, target);
        
        return dp[i][shiftedIndex] = add + subtract;
    }
}
