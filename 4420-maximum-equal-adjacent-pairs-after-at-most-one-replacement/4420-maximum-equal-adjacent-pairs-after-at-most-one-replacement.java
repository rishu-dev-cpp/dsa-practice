class Solution {
    public int maxEqualAdjacentPairs(int[] nums) {
        int pahle = 0;
        int maxPair = 0;
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length - 1; i++) {
            int a = nums[i];
            int b = nums[i + 1];
            if (a == b)
                pahle++;
            else {
                String key = Math.min(a, b) + "kyare" + Math.max(a, b);
                int count = map.getOrDefault(key, 0) + 1;

                map.put(key, count);

                maxPair = Math.max(maxPair, count);
            }
        }
        return maxPair + pahle;
    }
}