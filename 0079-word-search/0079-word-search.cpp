class Solution {
public:
    int m, n; // Board ka size globally rakh liya taaki baar-baar pass na karna pade

    // ð¥ MAIN BACKTRACKING FUNCTION (DFS STYLE)
    bool find(vector<vector<char>>& board, int i, int j, string& word, int idx) {
        
        // ð¯ BASE CASE 1 (JEET): Agar saare akshar mil gaye, toh khushi-khushi true lautao
        if (idx == word.length())
            return true;

        // ð BASE CASE 2 (HAAR / INVALID CHECKS):
        // 1. i < 0 ya j < 0 -> Board ke upar ya left se baahar nikal gaye
        // 2. i >= m ya j >= n -> Board ke neeche ya right se baahar nikal gaye
        // 3. board[i][j] == '@' -> Yeh dabba hum isi raste mein PEHLE HI use kar chuke hain
        // 4. board[i][j] != word[idx] -> Jo akshar chahiye tha, woh nahi mila (Galat Rasta!)
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '@' || board[i][j] != word[idx])
            return false;

        // ð PUSH STEP (VISITED MARK KARNA):
        // Akshar match ho gaya! Ab ise safe rakhlo aur board par '@' chipka do 
        // taaki yeh dabba is word ke liye DOBARA use na ho sake (Gaddari rokne ke liye)
        char temp = board[i][j];
        board[i][j] = '@';

        // ð RECURSION (CHARO DISHAO MEIN CHHALAANG):
        // '||' (OR) lagaya hai, matlab charo mein se KISI EK bhi raste se word mil gaya toh kaam khatam!
        if (find(board, i - 1, j, word, idx + 1) ||  // â¬ï¸ UP (Ek row upar)
            find(board, i + 1, j, word, idx + 1) ||  // â¬ï¸ DOWN (Ek row neeche)
            find(board, i, j - 1, word, idx + 1) ||  // â¬ï¸ LEFT (Ek col peeche)
            find(board, i, j + 1, word, idx + 1)) {  // â¡ï¸ RIGHT (Ek col aage)
            return true; // Agar kahi se bhi mil gaya, toh yahi se true lekar nikal lo!
        }

        // ð POP/BACKTRACK STEP (SAAF-SAFAI):
        // Agar charo taraf ghumne par bhi word NAHI mila, matlab yeh dabba galat raste par hai.
        // Wapas laut te waqt '@' hatao aur purana akshar wapas rakhdo, 
        // taaki koi doosra naya rasta is dabbe ko use kar sake.
        board[i][j] = temp;

        return false; // Is raste se kuch nahi mila, toh false lautao
    }

    // ð MAIN DRIVER FUNCTION
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();    // Total Rows
        n = board[0].size(); // Total Columns

        // ð GRID SCANNER: Poore board par ek-ek karke ghumo
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Agar board ka current akshar word ke PEHLE akshar se match hota hai,
                // sirf TABHI wahan se dhoondhna (find call) shuru karo!
                if (board[i][j] == word[0] && find(board, i, j, word, 0)) {
                    return true; // Agar poora word mil gaya, toh pure function se true!
                }
            }
        }
        return false; // Agar poore board par kahin bhi nahi mila, toh false
    }
};