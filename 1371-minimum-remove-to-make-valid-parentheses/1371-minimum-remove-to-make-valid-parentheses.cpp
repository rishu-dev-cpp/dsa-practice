class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st; // Yeh valid/invalid '(' ke indices ko yaad rakhega
        
        // Poori string par ghumo aur galat brackets pehchano
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i); // '(' mila toh uski index stack mein daal di
            } 
            else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop(); // Jodi ban gayi! Stack se pichle '(' ko hatao
                } else {
                    s[i] = '#'; // Kachra ')' mila! Iski jagah '#' chipkao
                }
            }
        }
        
        // Loop ke baad agar stack mein kuch bacha hai, 
        // toh woh aise '(' hain jinki jodi nahi bani. Unhe bhi '#' banao
        while (!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }
        
        // Nayi string banao jisme '#' ko shamil mat karna
        string ans = "";
        for (char c : s) {
            if (c != '#') {
                ans += c;
            }
        }
        
        return ans;
    }
};