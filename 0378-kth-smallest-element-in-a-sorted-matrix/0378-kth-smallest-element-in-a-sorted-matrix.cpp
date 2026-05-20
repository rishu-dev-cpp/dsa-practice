class Solution {
public:

    //StairCase jaise, Like search in 2D sorted matrix
    int countLessEqual(vector<vector<int>>& matrix,int mid,int n){
        int count = 0;
        int row = 0;
        int col = n -1;

        while(row<n && col>=0){
            if(matrix[row][col]<=mid){
                count += (col + 1);
                row++;
            }else col--;
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
    /*  priority_queue<int> pq;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k) pq.pop();
            }
        }return pq.top(); 
    */
        int size = matrix.size();

        int low = matrix[0][0];
        int  high = matrix[size-1][size-1];
        int ans = low;

        while(low<=high){
            int mid= low+(high-low)/2;
            if (countLessEqual(matrix, mid, size) >= k) {
                ans = mid;      // Yeh potential answer ho sakta hai
                high = mid - 1; // Aur chhota answer dhoondhne left jao
            } else {
                low = mid + 1;  // Agar log kam padh gaye, toh right jao
            }
        }
        return ans;
    }
};