class Solution {
public:
    vector<string> result;
    
    // Telephone ke buttons ka nakshe (Mapping)
    // Index 2 par "abc" hai, Index 3 par "def" hai...
    vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(int index, string& digits, string& currentStr) {
        // Base Case: Agar humne saare digits dekh liye, toh answer save karo aur lout jao
        if (index == digits.length()) {
            result.push_back(currentStr);
            return;
        }

        // 1. Pata karo ki abhi kis digit par hain aur uske paas kaunse letters hain
        int currentDigit = digits[index] - '0'; // '2' ko number 2 banaya
        string letters = mapping[currentDigit]; // Agar 2 hai, toh letters milenge "abc"

        // 2. Us digit ke har ek letter ke liye raasta check karo
        for (int i = 0; i < letters.length(); i++) {
            currentStr.push_back(letters[i]);    // Letter ko jhole mein daala (Take)
            solve(index + 1, digits, currentStr); // Agle digit ke liye recursion chalaya
            currentStr.pop_back();               // Wapas aate hi jhola saaf kiya (Backtrack)
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Khali string ke liye khali answer
        
        string currentStr = "";
        solve(0, digits, currentStr); // Index 0 se shuruat
        return result;
    }
};