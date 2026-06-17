class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st; // Yeh valid folder ke naamon ko yaad rakhega
        string res;

        for(int i = 0; i < path.length(); i++) {
            // 1. Agar '/' mile toh chupchaap aage badho, iska koi kaam nahi hai
            if(path[i] == '/') continue;

            // 2. Agar koi character mila, toh poora word (folder ka naam) nikal lo
            string temp = "";
            while(i < path.length() && path[i] != '/') {
                temp += path[i];
                i++;
            }

            // 3. Ab check karo jo word mila woh kya keh raha hai:
            if(temp == ".") {
                continue; // '.' matlab same folder, kuch mat karo
            } 
            else if(temp == "..") {
                if(!st.empty()) st.pop(); // '..' matlab ek step piche jao, toh top folder ko uda do
            } 
            else {
                st.push(temp); // Agar normal naam hai (jaise "home"), toh stack mein daal do
            }
        }

        // STACK SE PATH BANANA
        // Stack mein folders seedhe order mein hote hain par nikalte ulte hain.
        // Isiliye hum "res = '/' + st.top() + res" kar rahe hain taaki order sahi rahe.
        while(!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }

        // Agar stack khali tha aur string 0 size ki bani, 
        // toh Unix mein root directory ko hamesha "/" likhte hain.
        if(res.size() == 0) {
            return "/";
        }

        return res;
    }
};