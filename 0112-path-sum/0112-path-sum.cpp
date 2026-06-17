/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Agar dabba hi khali hai, toh rasta galat hai
        if (root == nullptr) return false;

        // Agar aakhiri patti (Leaf) par hain, toh check karo kya paise poore hisab hue?
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum; 
        }

        // Apne paise kam karo aur bacchon ko bol do dhoondhne ke liye
        int remainingMoney = targetSum - root->val;
        
        return hasPathSum(root->left, remainingMoney) || hasPathSum(root->right, remainingMoney);
    }
};