class Solution {
public:
    bool static compare(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]){
           return a[1]>b[1]; // End time bade se chhota
        }
        return a[0]<b[0]; // Start time chhote se bada
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), compare);

        int count = 0;
        int maxEnd = 0;
        for(int i = 0; i<intervals.size();i++){
            int curent = intervals[i][1];

            if(curent > maxEnd){
                count++;
                maxEnd = curent;
            }
        }
        return count;
    }
};