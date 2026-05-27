class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Agar target mil gaya, toh true return karo
            if (nums[mid] == target) return true;

            // DUPLICATES KA CURE: Jab teeno barabar ho jayein
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++; // jb same element h sb to age badho
                high--; // jb same element h sb to piche a jao
                continue; // Agli iteration par jao, niche ka check mat karo abhi
            }

            // BAQI POORA CODE EXACTLY PART 1 WAALA HAI 
            
            // Step 1: Check karo kya Left part sorted hai?
            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1; // Left mein jao
                } else {
                    low = mid + 1;  // Right mein jao
                }
            } 
            // Step 2: Agar left sorted nahi hai, toh pakka Right part sorted hai
            else {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;  // Right mein jao
                } else {
                    high = mid - 1; // Left mein jao
                }
            }
        }
        // Agar poore loop mein kahin nahi mila
        return false;
    }
};