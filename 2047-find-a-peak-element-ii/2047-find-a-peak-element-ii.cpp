class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        int low = 0, high = cols - 1;
        
        // Columns par normal Binary Search
        while (low <= high) {
            int mid = low + (high - low) / 2; // Is baar mid matlab mid-column
            // 1. Is 'mid' column mein sabse bada number (Neta) dhoondho
            int maxRow = 0; 
            for (int i = 0; i < rows; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i; // maxRow mein us sabse bade element ki row mil jayegi
                }
            }
            // 2. Ab teen simple variables banao: current, left, aur right
            int current = mat[maxRow][mid];
            
            // Agar boundary se baahar hain, toh value -1 maan lo
            int left  = (mid > 0)        ? mat[maxRow][mid - 1] : -1;
            int right = (mid < cols - 1) ? mat[maxRow][mid + 1] : -1;
            
            // 3. Peak check karo (Kya current apne left aur right dono se bada hai?)
            if (current > left && current > right) {
                return {maxRow, mid}; // Badhai ho, peak mil gaya!
            }
            
            // Agar left waala bada hai, toh left half mein dhoondho
            if (left > current) {
                high = mid - 1;
            } 
            // Agar right waala bada hai, toh right half mein dhoondho
            else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};