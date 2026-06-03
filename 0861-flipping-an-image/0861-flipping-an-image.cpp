class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (auto& row : image) { 
            for (int i=0;i<(n+1)/2;i++){
                int temp = row[i];
                row[i] = row[n - i - 1] ^ 1;
                row[n - i - 1] = temp ^ 1;
            }
        }
        return image;
    }
};
