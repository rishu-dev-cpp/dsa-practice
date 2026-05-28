class Solution {
public:
    // Ek dabba jo yaad rakhega ki kis index se answer mil chuka hai
    vector<int> dp; 
    // Dictionary ko set mein daal denge taaki search karna O(1) ho jaye
    unordered_set<string> wordSet;

    bool solve(int start, string& s) {
        // Base Case: Agar hum ghumte-ghumte string ke ekdam aakhiri mein pahunch gaye, 
        // iska matlab peeche ke saare tukde perfectly match ho chuke hain!
        if (start == s.length()) return true;

        // Agar humne is index se pehle hi solve kiya hua hai, toh direct answer return karo
        if (dp[start] != -1) return dp[start];

        // Hum 'start' index se lekar aage tak ke saare tukde (substrings) check karenge
        for (int end = start + 1; end <= s.length(); end++) {
            string currentWord = s.substr(start, end - start);

            // Agar currentWord dictionary mein hai, AUR bacha hua hissa bhi true return kare
            if (wordSet.count(currentWord) && solve(end, s)) {
                return dp[start] = 1; // Is index ke liye answer True (1) save kar lo
            }
        }

        // Agar saare cuts try karne ke baad bhi baat nahi bani, toh is index se answer nahi mil sakta
        return dp[start] = 0; // Is index ke liye answer False (0) save kar lo
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // Saare words ko set mein daal do taaki dhoondhna aasan ho
        for (string word : wordDict) {
            wordSet.insert(word);
        }

        // DP array ko string ke length ke barabar size do aur -1 se bhar do
        dp.assign(s.length(), -1);

        // Index 0 se shuru karo checking
        return solve(0, s);
    }
};