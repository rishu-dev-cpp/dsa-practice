class Solution {
    public int maxProduct(int[] nums) {
        int res = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        for (int i = 1; i < nums.length; i++) {
            int n = nums[i];

            if (n < 0) {
                int temp = currMax;
                currMax = currMin;
                currMin = temp;
            }
            currMax = Math.max(n, n * currMax);
            currMin = Math.min(n, n * currMin);

            res = Math.max(currMax, res);
        }
        return res;
    }
}
