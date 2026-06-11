class Solution {
public:
    vector<vector<int>> result;

    void findCombinations(int index, int target, vector<int>& candidates, vector<int>& current) {
        // Agar target poora ho gaya, toh answer mil gaya!
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Agar target minus mein chala gaya ya array khatam ho gaya
        if (target < 0 || index == candidates.size()) {
            return;
        }

        // TAKE (Current element ko jhole mein le lo)
        // Yeh hum tabhi kar sakte hain jab current element target se chhota ya barabar ho
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            
            // index ko badhaya nahi (index hi bheja) kyunki dubara le sakte hain!
            findCombinations(index, target - candidates[index], candidates, current);
            
            current.pop_back(); // Backtrack (saaf-safai)
        }

        // NOT TAKE (Current element ko chhod kar agle par badho)
        // Ab is element ko chhod kar index + 1 par chale jao
        findCombinations(index + 1, target, candidates, current);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        
        // Shuruat karenge index 0 se aur poore target ke sath
        findCombinations(0, target, candidates, current);
        
        return result;
    }
};