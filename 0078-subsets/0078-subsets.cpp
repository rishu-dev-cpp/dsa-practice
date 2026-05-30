class Solution {
public:
    vector<vector<int>> result; // Isme saare subsets store honge

    void solve(int index, vector<int>& nums, vector<int>& current) {
        // Base Case: Jab hum saare elements se unki choice pooch chuke hain
        if (index == nums.size()) {
            result.push_back(current); // Jo bhi subset bana, use result mein daal do
            return;
        }

        // Choice 1: Take (Pehle element ko include KARO)
        current.push_back(nums[index]);   // Element ko jhole mein daala
        solve(index + 1, nums, current);   // Agle element par chale gaye

        // Backtracking Step: Jhole ko waise hi saaf karo jaise pehle tha
        current.pop_back();                // Yeh line ab Don't Take se PEHLE aayegi

        // Choice 2: Don't Take (Element ko include MAT karo)
        solve(index + 1, nums, current);   // Saaf jhole ke saath agle element par gaye
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current; // Yeh humara chota jhola hai jo har raste ka subset banayega
        solve(0, nums, current); // Index 0 se shuruat karo
        return result;
    }
};