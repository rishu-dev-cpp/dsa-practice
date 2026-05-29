class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s.size()!=t.size()) return false;
        // for(int i=0;i<s.size();i++) {
        //     if(s[i]!=t[i]) return false;
        // }return true; O(nlog n)
        if(s.size()!=t.size()) return false;
        int count[26] = {0};
        for(int i=0;i<s.size();i++) {
            count[s[i]-'a'] ++;
            count[t[i]-'a'] --;
        }
        for(int i=0;i<26;i++) {
            if(count[i]!=0) {
                return false;
            }
        }return true; //O(n)
    }
};