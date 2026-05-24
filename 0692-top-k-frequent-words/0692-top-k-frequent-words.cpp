class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // 1. Har word ki frequency count karo
        unordered_map<string, int> freq;
        for (const string& w : words) {
            freq[w]++;
        }

        // 2. Saare unique words ko ek vector mein daal lo
        vector<string> uniqueWords;
        for(auto& it:freq){
            uniqueWords.push_back(it.first);
        }

        // 3. Custom sorting using Lambda!
        // Inside [] we use '&' so that lambda can access the 'freq' map from outside.
        sort(uniqueWords.begin(), uniqueWords.end(), [&](const string& a, const string& b) {
            if(freq[a] != freq[b]){
                return freq[a] > freq[b]; // Badi frequency pehle (Descending)
            }
            return a < b; // Barabar frequency par alphabetical order (Ascending)
        });
        // 4. Pehle k elements uthao aur answer banakar bhej do
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(uniqueWords[i]);
        }

        return ans;
    }
};