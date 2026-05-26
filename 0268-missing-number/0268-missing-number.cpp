class Solution {
public:

    /* Note:
        Whenever a problem says:
        one element missing
        duplicates cancel
        O(1) space required

        always think about:

        XOR (0 se n tk XOR lelo)

        Final Ans = (loop ka result) ^ (array ka element)
        for example:-
        [3,0,1]
        FInal Ans = (0^1^2^3) ^ (3^0^1)
    */
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<=n;i++){
            ans^=i;
        }

        for(int num : nums){
            ans ^= num;
        }

        return ans;
    }
};