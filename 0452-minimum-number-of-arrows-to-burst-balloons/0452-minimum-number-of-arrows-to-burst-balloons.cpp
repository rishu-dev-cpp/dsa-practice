class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end());

        int nonOverlap = 1;         // Shuruat 1 se hogi, pehle balloon ke liye
        int prevEnd = points[0][1]; // Pehle waale ka End

        for (int i = 1; i < points.size(); i++) {
            int currStart = points[i][0];
            int currEnd = points[i][1];

            // Check Overlap
            if (currStart <= prevEnd) { // '<=' hoga kyunki touch points bhi overlap hain
                // Jo jaldi khatam ho rha h use rkho, bade waale ko hata do
                prevEnd = min(prevEnd, currEnd);
            } else {
                // Koi takraav nahi, yaani naya arrow chahiye!
                nonOverlap++;
                prevEnd = currEnd;
            }
        }
        return nonOverlap; 
    }
};