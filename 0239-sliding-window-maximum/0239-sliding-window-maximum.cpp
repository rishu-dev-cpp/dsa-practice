class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            // 1. Window se bahar waalon ko nikalo (Front se)
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }
            // 2. Kamzoro ko nikalo (Back se) - Current se chote saare hata do
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            // 3. Push the element 
            dq.push_back(i);

            // 4. Result add karo (Jab window size k ho jaye)
            if(i >= k-1){
                result.push_back(nums[dq.front()]);
            }
        }return result;
    }
};