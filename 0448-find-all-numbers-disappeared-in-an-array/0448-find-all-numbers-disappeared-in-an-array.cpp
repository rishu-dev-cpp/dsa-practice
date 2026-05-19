class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(1+n,0);
        for(int x:nums){
            count[x]++;
        }
        vector<int> vec;
        vec.reserve(n);
        for(int i=1;i<n+1;i++){
            if(count[i]==0){
                vec.push_back(i);
            }
        }return vec;
    }
};