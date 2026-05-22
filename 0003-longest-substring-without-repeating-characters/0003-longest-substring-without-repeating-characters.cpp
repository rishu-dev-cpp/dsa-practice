class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0, right = 0;
        int maxLen = 0;
        for(right = 0;right < s.length();right++){
            mp[s[right]]++;

            while(mp[s[right]]>1){
                mp[s[left]]--;
                left++; // shrink
            }
            maxLen = max(maxLen, right - left + 1);
        }return maxLen;
    }
};