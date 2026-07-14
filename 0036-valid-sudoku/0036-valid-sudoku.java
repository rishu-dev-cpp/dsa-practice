import java.util.HashSet;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        // Ek single HashSet jo saari unique IDs store karega
        HashSet<String> seen = new HashSet<>();

        // Poore 9x9 board par ghumo
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char number = board[i][j];

                // Agar khali dabba à¤¹à¥ (dot '.'), toh chhor do aur aage badho
                if (number != '.') {
                    
                    // Har number ke liye 3 unique IDs banakar set mein daalo
                    // Agar .add() false return karta hai, matlab duplicate mil gaya!
                    if (!seen.add(number + " in row " + i) ||
                        !seen.add(number + " in col " + j) ||
                        !seen.add(number + " in box " + (i / 3) * 3 + (j / 3))) {
                        
                        return false; // Turnt bolo - Sudoku invalid hai!
                    }
                }
            }
        }
        
        return true; // Agar sab sahi-sahi add ho gaya, toh Sudoku valid hai!
    }
}