class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length()<p.length()) return ans;

        vector<int> pcount(26,0);
        vector<int> scount(26,0);

        for(char c: p){
            pcount[c-'a']++;
        }

        int left = 0;
        for(int right = 0;right<s.length();right++){
            scount[s[right]-'a']++;

            if((right-left+1)>p.length()){
                scount[s[left]-'a']--;
                left++;
            }
            if((right-left+1)==p.length()){
                if(scount==pcount){
                    ans.push_back(left);
                }
            }
        }return ans;
    }
};