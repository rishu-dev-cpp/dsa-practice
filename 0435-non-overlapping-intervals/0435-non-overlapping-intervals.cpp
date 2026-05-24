class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int removals = 0;
        int prevEnd = intervals[0][1]; // Pehle waale ka End

        // 2. Loop chalao
        for (int i = 1; i < intervals.size(); i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            // Check Overlap
            if (currStart < prevEnd) {
                removals++; // Ek ko hatana padega
                // Jo jaldi khatam ho rha h use rkho, bade waale ko hata do
                prevEnd = min(prevEnd, currEnd);
            } else {
                // Koi takraav nahi, aage badho
                prevEnd = currEnd;
            }
        }

        return removals;
    }
};