class Solution {
public:
    vector<string> result;

    // 1. Badlav: string ke aage '&' laga diya (Ab yeh reference ban gaya)
    void backtrack(int open_count, int close_count, int n, string& current) {
        // Base Case bilkul same rahega
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Take '('
        if (open_count < n) {
            current.push_back('('); // 2. Badlav: Pehle string mein '(' daalo
            
            backtrack(open_count + 1, close_count, n, current); // Agla call kiya
            
            current.pop_back(); //  BACKTRACK: Wapas aate waqt use baahar nikalo (Saaf-safai)
        }

        // Take ')'
        if (close_count < open_count) {
            current.push_back(')'); // Pehle string mein ')' daalo
            
            backtrack(open_count, close_count + 1, n, current); // Agla call kiya
            
            current.pop_back(); // ð BACKTRACK: Wapas aate waqt use bhi baahar nikalo
        }
    }

    vector<string> generateParenthesis(int n) {
        string current = ""; // Khali string banayi
        
        // Pass by reference ke liye 'current' variable bhej rahe hain
        backtrack(0, 0, n, current); 
        return result;
    }
};