class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
    /*  int totalNegative = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            int left = 0, right = n - 1;
            int firstNegative = n;
            while(left<=right){
                int mid = left + (right -left)/2;
                if(grid[i][mid]<0){
                    firstNegative = mid;
                    right = mid - 1;
                }else left = mid + 1;

            }totalNegative += (n - firstNegative);
        }return totalNegative;
        */

        int m = grid.size();
        int n = grid[0].size();
        
        int row = m - 1; 
        int col = 0;   
        int totalNegatives = 0;
        
        while (row >= 0 && col < n) {
            if (grid[row][col] < 0) {
                totalNegatives += (n - col);
                row--; 
            } else {
                col++; 
            }
        }
        return totalNegatives;
    }
};