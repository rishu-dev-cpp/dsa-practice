class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(k, 0);
        count[0] = 1;
        int prefixSum = 0, ans = 0;
        for(int num : nums){
            prefixSum += num;
            int rem = prefixSum % k;
            if(rem<0) rem+=k;

            ans+=count[rem];

            count[rem]++;
        }return ans;
    }
};