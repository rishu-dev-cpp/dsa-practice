/*// recursion
class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        return help(0, target, nums);
    }
    private boolean help(int idx, int target, int[] nums) {
        if (target == 0)
            return true;
        if (idx == nums.length)
            return false;

        boolean notake = help(idx + 1, target, nums);

        boolean take;
        if (nums[idx] <= target) {
            take = help(idx + 1, target - nums[idx], nums);
        } else {
            take = false;
        }
        return take || notake;
    }
}
*/
// dp top - bottom
class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        Boolean[][] dp = new Boolean[nums.length + 1][target + 1];

        return help(0, target, nums, dp);
    }
    private static boolean help(int idx, int target, int[] nums, Boolean[][] dp) {
        if (target == 0)
            return true;
        if (idx == nums.length)
            return false;

        if (dp[idx][target] != null)
            return dp[idx][target];

        boolean notake = help(idx + 1, target, nums, dp);

        boolean take;
        if (nums[idx] <= target) {
            take = help(idx + 1, target - nums[idx], nums, dp);
        } else {
            take = false;
        }
        return dp[idx][target] = take || notake;
    }
}