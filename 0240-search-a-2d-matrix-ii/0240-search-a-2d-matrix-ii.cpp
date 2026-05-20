class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     /* int m = matrix.size();

        int n = matrix[0].size();

        for(int i=0;i<m;i++){

            int low = 0, high = n - 1;

            while(low<=high){

                int mid = low + (high-low)/2;

                if(matrix[i][mid]==target) return true;

                else if(matrix[i][mid]<target){

                    low = mid + 1;

                }else high = mid - 1; 

            }

        }return false;
        */
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = m - 1; 
        int col = 0;    
        
        while (row >= 0 && col < n) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                row--; 
            } else {
                col++; 
            }
        }
        
        return false;
    }
};