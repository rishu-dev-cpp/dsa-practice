class Solution {
public:
    vector<vector<int>> ans; // Final result store karne ke liye global variable

    void solve(TreeNode* root, int targetSum, vector<int>& curr_path) {
        if (root == nullptr) return; // Base Case 1: Khaali dabba

        // 1. Current node ko raste (path) mein shamil karo
        curr_path.push_back(root->val);

        // 2. Check karo kya hum leaf node par hain aur sum match ho gaya?
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == targetSum) {
                ans.push_back(curr_path); // Sahi raasta mila, list mein save karo
            }
            // â ï¸ YAAD RAKHO: Yahan se return nahi karna hai! Neeche pop_back() hona zaroori hai.
        }

        // 3. Left aur Right dono bacchon ke paas jao (Target kam karke)
        if (root->left != nullptr) {
            solve(root->left, targetSum - root->val, curr_path);
        }
        if (root->right != nullptr) {
            solve(root->right, targetSum - root->val, curr_path);
        }

        // ð BACKTRACK: Wapas upar jaate waqt current node ko raste se hatao
        curr_path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear(); // Purana kachra saaf karo
        vector<int> curr_path;
        solve(root, targetSum, curr_path);
        return ans;
    }
};