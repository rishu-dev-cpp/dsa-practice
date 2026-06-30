class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for(int i=0;i<nums.size()-1;i++) {
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             return {i,j};
        //         }
        //     }
        // }return {}; O(n^2)
        unordered_map<int, int> seen;
        for(int i=0;i<nums.size();i++){
            int left = target - nums[i];
            if(seen.find(left) != seen.end()){ // if (seen.count(complement))
                return {seen[left],i};
            }else seen[nums[i]]=i;
        }return {};
    }
};