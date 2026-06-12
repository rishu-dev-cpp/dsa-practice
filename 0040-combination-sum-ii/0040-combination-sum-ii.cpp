class Solution {
public:
    vector<vector<int>> result;

    void findCombinations(int index, int target, vector<int>& candidates, vector<int>& current) {
        // Base Case 1: Agar target poora ho gaya, toh answer mil gaya!
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Loop chalega current index se lekar array ke end tak
        for (int i = index; i < candidates.size(); i++) {
            
            // DUPLICATE SKIP TRICK (Subsets II waali):
            // Agar element apne pichle waale ke barabar hai aur hum loop ke shuruat mein nahi hain
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue; // Isko mat lo, agle loop par chalaang lagao
            }

            // ð¥ OPTIMIZATION: Agar current element hi target se bada hai, 
            // toh aage ke saare elements toh aur bhi bade honge (kyunki array sorted hai).
            // Isiliye loop ko yahin BREAK kar do, aage check karne ki zaroorat hi nahi!
            if (candidates[i] > target) {
                break;
            }

            // 1. Element ko jhole mein lo
            current.push_back(candidates[i]);
            
            // 2. Agle element par jao (i + 1 bhejenge kyunki har element ek hi baar use ho sakta hai)
            findCombinations(i + 1, target - candidates[i], candidates, current);
            
            // 3. Backtrack (saaf-safai)
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        
        // Sabse zaroori step: Sort karo taaki duplicates ek sath aa sakein
        sort(candidates.begin(), candidates.end());
        
        findCombinations(0, target, candidates, current);
        
        return result;
    }
};