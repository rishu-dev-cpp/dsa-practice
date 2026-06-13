class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0); // Saare functions ka time shuruat mein 0 rakh liya
        stack<int> st;            // Yeh chalne waale functions ki ID yaad rakhega
        int prev_time = 0;        // Pichla event kis time par hua tha

        for (string& log : logs) {
            // ð ï¸ STRING PARSING: Log string se ID, Status, aur Timestamp nikalna
            // Log format: "id:status:timestamp" (E.g., "0:start:2")
            stringstream ss(log);
            string id_str, status, time_str;
            
            getline(ss, id_str, ':');
            getline(ss, status, ':');
            getline(ss, time_str, ':');
            
            int id = stoi(id_str);
            int timestamp = stoi(time_str);

            // ð AGAR NAYA FUNCTION SHURU HUA HAI:
            if (status == "start") {
                // Agar stack khali nahi hai, matlab koi function pehle se chal raha tha!
                if (!st.empty()) {
                    // Jo chal raha tha (st.top()), uske khate mein ab tak ka time jod do
                    result[st.top()] += timestamp - prev_time;
                }
                st.push(id);          // Naye function ko stack mein daalo
                prev_time = timestamp; // Ab se naya function chalega, toh prev_time update karo
            } 
            // ð AGAR CURRENT FUNCTION KHATAM HUA HAI:
            else {
                // Formula: current_time - prev_time + 1 (Kyunki end log time ke aakhiri tak chalta hai)
                result[st.top()] += timestamp - prev_time + 1;
                st.pop(); // Kaam khatam, stack se baahar nikal do
                
                // ð Agla event ab iske agle second (timestamp + 1) se shuru mana jayega
                prev_time = timestamp + 1;
            }
        }
        
        return result;
    }
};