class Solution {
    public int longestSubarray(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;

        for (int l = 0; l < n; l++) {
            long sum = 0;
            boolean[] seen = new boolean[k];

            for (int r = l; r < n; r++) {
                sum += nums[r];

                int rem = (int)((sum % k + k) % k);

                // Current element bhi negate ho sakta hai
                int x = (int)((2L * nums[r] % k + k) % k);
                seen[x] = true;

                // Without negation
                if (rem == 0) {
                    ans = Math.max(ans, r - l + 1);
                }

                // One element negate karke
                if (seen[rem]) {
                    ans = Math.max(ans, r - l + 1);
                }
            }
        }

        return ans;
    }
}