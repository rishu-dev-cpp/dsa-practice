class Solution {
public:
    void backtrack(int idx, vector<int>& nums, vector<vector<int>>& result) {
        // Base Case: Agar hum array ke end tak pahunch gaye, matlab ek permutation taiyar hai
        if (idx == nums.size()) {
            result.push_back(nums); // Jo naya arrangement bana, use save kar lo
            return;
        }

        // Loop chalega current index se lekar aakhiri tak
        for (int i = idx; i < nums.size(); i++) {
            // 1. Choice: idx waale element ko i waale element se badlo
            swap(nums[idx], nums[i]);

            // 2. Agle index par jaakar baaki bache elements ko arrange karo
            backtrack(idx + 1, nums, result);

            // 3. Backtrack: Wapas aate waqt firse swap karke array ko purana jaisa banao
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Shuruat karenge index 0 se
        backtrack(0, nums, result);
        
        return result;
    }
};