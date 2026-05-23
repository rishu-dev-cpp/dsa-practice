class Solution {
public:
    string minWindow(string s, string t) {
        // Frequency array string t ke characters ke liye
        vector<int> m(128, 0);
        for (char c : t) m[c]++;

        int left = 0, right = 0;
        int minLeft = 0;             // Minimum window ka starting index save karne ke liye
        int minLen = INT_MAX;        // Minimum length track karne ke liye
        int required = t.length();   // Kitne characters chahiye total

        while (right < s.length()) {
            // Agar current character t mein chahiye tha, toh required kam karo
            if (m[s[right]] > 0) {
                required--;
            }
            // Window mein character le liya, toh uski frequency kam kar do
            m[s[right]]--;
            right++;

            // YAHAAN SE SHRINKING SHURU: Jab window valid ho jaye
            while (required == 0) {
                // Apna answer update karo agar choti window mili hai toh
                if (right - left < minLen) {
                    minLeft = left;
                    minLen = right - left;
                }

                // Ab left waale character ko window se bahar nikaalo
                m[s[left]]++;
                // Agar woh character kaam ka tha aur ab kam pad gaya hai, toh required badhao
                if (m[s[left]] > 0) {
                    required++;
                }
                left++; // Left ko aage khiskayo
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};