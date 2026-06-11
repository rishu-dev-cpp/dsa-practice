class Solution {
public:
    vector<vector<int>> result;

    void findSubsets(int index, vector<int>& nums, vector<int>& current) {
        // Har ek step par jo current jhola bana hai, woh apne aap mein ek valid subset hai!
        // Isiliye base case ka wait kiye bina, har call par ise result mein push karo.
        result.push_back(current);

        // Loop chalega current index se lekar array ke end tak
        for (int i = index; i < nums.size(); i++) {
            //  DUPLICATE SKIP TRICK: 
            // Agar element apne pichle waale ke barabar hai, aur hum loop ke shuruat mein nahi hain (i > index)
            // toh use mat lo, chupchaap aage badho (skip karo)
            if (i > index && nums[i] == nums[i - 1]) {
                continue; 
            }

            // 1. Element ko jhole mein lo
            current.push_back(nums[i]);

            // 2. Agle element ke liye recursion call karo (i + 1 bhejenge)
            findSubsets(i + 1, nums, current);

            // 3. Backtrack (saaf-safai)
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        
        // Sabse zaroori step: Array ko sort karo taaki saare duplicates ek sath baith jayein
        sort(nums.begin(), nums.end());
        
        // Function call kiya
        findSubsets(0, nums, current);
        
        return result;
    }
};