class Solution {
public:

    int count(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int left = 0;
        int right = 0;
        int countArr = 0;
        for(int right = 0;right <nums.size();right++){
            mp[nums[right]]++;

            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }left++;
            }
            countArr += (right - left + 1);
        }return countArr;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return count(nums, k) - count(nums, k-1);
    }
};