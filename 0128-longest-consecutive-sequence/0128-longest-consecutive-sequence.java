class Solution {
    public int longestConsecutive(int[] nums) {
        /*
        int maxl = 0;
        HashSet<Integer> store = new HashSet<>();

        for(int num : nums){
            store.add(num);
        }

        for(int i = 0; i < nums.length;i++){
            int count = 0, curr = nums[i]; 
            while(store.contains(curr)){
                count++;
                curr++;
            }
            maxl = Math.max(maxl, count);
        }
        return maxl;
        */
        int maxl = 0;
        HashSet<Integer> seen = new HashSet<>();

        for(int num : nums){
            seen.add(num);
        }

        for(int num : seen){
            if(!seen.contains(num-1)){
                int count = 0;
                int curr = num;
                while(seen.contains(curr)){
                    count++;
                    curr++;
                }
                maxl = Math.max(maxl, count);
            }
        }
        return maxl;
    }
}
