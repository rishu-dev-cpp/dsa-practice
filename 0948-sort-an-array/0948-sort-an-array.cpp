class Solution {
public:
    // Yeh function do sorted hisson ko aapas mein jodne ka kaam karta hai
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp; // Ek temporary dabba sorted elements rakhne ke liye
        
        int left = low;      // Left half ka shuruat
        int right = mid + 1; // Right half ka shuruat
        
        // Jab tak dono hisson mein elements baaki hain
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        
        // Agar left half mein kuch elements bach gaye hon
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        
        // Agar right half mein kuch elements bach gaye hon
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }
        
        // Ab temp se saare sorted elements ko wapas asli array (nums) mein copy kar do
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    // Main function jo array ko aadha-aadha todta hai
    void mergeSort(vector<int>& nums, int low, int high) {
        // Base Case: Agar single element bacha ya invalid range hui toh ruk jao
        if (low >= high) return;
        
        int mid = low + (high - low) / 2;
        
        // Left wale aadhe hisse ko todo
        mergeSort(nums, low, mid);
        
        // Right wale aadhe hisse ko todo
        mergeSort(nums, mid + 1, high);
        
        // Ab dono sorted hisson ko mila do
        merge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};