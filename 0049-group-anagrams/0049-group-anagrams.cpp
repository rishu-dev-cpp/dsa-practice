class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string, vector<string>> mp; //{string type key : {string type}}
        // for(string s : strs) {
        //     string word = s;
        //     sort(word.begin(), word.end()); // string ko alphabetical order mein kiya
        //     mp[word].push_back(s); //'sorted' key par original string 's' ko daal denge
        // }
        // vector<vector<string>> ans;
        // for(auto hey : mp) {
        //     ans.push_back(hey.second); // hey.second matlab vector<string> map ke andr wala
        // }
        // return ans; // O(n*k*log k)
        //***************************
        // Dhyaan se dekho: Key ab ek 'vector<int>' hai, string nahi!
        map<vector<int>, vector<string>> mp;
        for(string s : strs){
            //26 size ka count array banao
            vector<int> count(26, 0);
            for(char c : s){
                count[c-'a']++;
            }
            // Is poore vector ko hi 'Key' ki tarah use kar lo
            // Jo words anagram honge, unka count vector ekdum same hoga
            mp[count].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& hey : mp) {
            ans.push_back(hey.second);
        }
        return ans;
    }
};