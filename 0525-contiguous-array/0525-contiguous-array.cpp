class Solution {
public:
    int findMaxLength(vector<int>& nums) {
            unordered_map<int, int> mp;
            int curSum = 0;
            int mxlen = 0;

            mp[0] = -1;

            for(int i=0;i<nums.size();i++){
                curSum += (nums[i]==0) ? -1:1;
                if(mp.find(curSum)!=mp.end()){
                    mxlen = max(mxlen, i-mp[curSum]);
                }else {
                    mp[curSum] = i;
                }
            }return mxlen;
    }
};