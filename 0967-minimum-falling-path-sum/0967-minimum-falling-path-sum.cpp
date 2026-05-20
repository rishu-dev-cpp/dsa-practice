class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix[0].size();

        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                int up = matrix[i-1][j];
                int upleft = (j>0) ? matrix[i-1][j-1] : INT_MAX;
                int upright = (j<n-1) ? matrix[i-1][j+1] : INT_MAX;

                matrix[i][j] += min(up,min(upleft, upright));
            }
        }
        int minSum = INT_MAX;
        for(int i=0;i<n;i++){
            minSum = min(minSum, matrix[n-1][i]);
        }
        return minSum;
    }
};