class Solution {
public:
    void backtrack(int idx, vector<int>& nums, vector<vector<int>>& result) {
        // Base Case: Agar hum array ke end tak pahunch gaye
        if (idx == nums.size()) {
            result.push_back(nums);
            return;
        }

        // DUPLICATE CHECKER SET: Yeh har ek level/call ke liye apna alag hoga
        unordered_set<int> swapped_elements;

        for (int i = idx; i < nums.size(); i++) {
            // Agar yeh element is level par pehle hi swap ho chuka hai, toh skip karo!
            if (swapped_elements.count(nums[i])) {
                continue;
            }

            // Is element ko set mein daal do taaki isko dubara is index par na laya jaye
            swapped_elements.insert(nums[i]);

            // 1. Choice: Swap karo
            swap(nums[idx], nums[i]);

            // 2. Recursion: Agle index par jao
            backtrack(idx + 1, nums, result);

            // 3. Backtrack: Wapas aate waqt Unswap karo
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        
        // Isme array ko sort karne ki bhi zaroori nahi hai, kyunki set har tarah ke duplicate ko pakad lega!
        backtrack(0, nums, result);
        
        return result;
    }
};