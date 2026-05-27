class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Agar target mil gaya, toh khushi-khushi index return karo
            if (nums[mid] == target) return mid;

            // Step 1: Check karo kya Left part sorted hai?
            if (nums[low] <= nums[mid]) {
                // Check karo kya target Left part ki range mein aata hai?
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1; // Left mein jao
                } else {
                    low = mid + 1;  // Right mein jao
                }
            } 
            // Step 2: Agar left sorted nahi hai, toh pakka Right part sorted hai
            else {
                // Check karo kya target Right part ki range mein aata hai?
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;  // Right mein jao
                } else {
                    high = mid - 1; // Left mein jao
                }
            }
        }
        // Agar loop khatam ho gaya aur target nahi mila
        return -1;
    }
};