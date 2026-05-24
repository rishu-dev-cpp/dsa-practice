class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            vector<int>& lastInterval = ans.back();
            vector<int>& currInterval = intervals[i];
            //Check Overlap: Agar naye ka Start, purane ke End se chota ya barabar hai
            if(currInterval[0]<=lastInterval[1]){
                // Merge karo: End time ko dono mein se jo bada ho woh bana do
                lastInterval[1]=max(lastInterval[1], currInterval[1]);
            }else{
                // Koi overlap nahi hai, chupchaap naya interval jod do
                ans.push_back(currInterval);
            }
        }return ans;
    }
};