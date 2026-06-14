class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;     // Yeh sirf numbers (k) ko yaad rakhega
        stack<string> strStack;  // Yeh piche bachi hui strings ko yaad rakhega
        
        string curr_str = "";    // Current level par jo string ban rahi hai
        int num = 0;             // Current number (k) jo ban raha hai

        for (char c : s) {
            // 1. Agar character digit hai (0-9)
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // E.g., '3' aur '2' milkar 32 ban sakein
            } 
            // 2. Agar opening bracket '[' aaya
            else if (c == '[') {
                numStack.push(num);      // Purana number stack mein safe karo
                strStack.push(curr_str); // Purani string stack mein safe karo
                
                num = 0;                 // Naye bracket ke liye reset
                curr_str = "";           // Naye bracket ke liye reset
            } 
            // 3. Agar closing bracket ']' aaya -> ASLI KHEL!
            else if (c == ']') {
                int repeat_count = numStack.top();
                numStack.pop();
                
                string prev_str = strStack.top();
                strStack.pop();
                
                // Current string ko 'repeat_count' jitni baar repeat karo
                string temp = "";
                for (int i = 0; i < repeat_count; i++) {
                    temp += curr_str;
                }
                
                // Purani string ke aage is repeated string ko jod kar update karo
                curr_str = prev_str + temp;
            } 
            // 4. Agar normal alphabet (a-z) hai
            else {
                curr_str += c;
            }
        }
        
        return curr_str; // Aakhiri mein poori decoded string isi mein bachegi
    }
};