class Solution {
    public boolean checkValidString(String s) {
        int minOpen = 0; // Min possible open '(' count
        int maxOpen = 0; // Max possible open '(' count

        for (char c : s.toCharArray()) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // c == '*'
                minOpen--; // Treat '*' as ')'
                maxOpen++; // Treat '*' as '('
            }

            // Guard 1: Too many ')' -> even maximum '(' can't fix it
            if (maxOpen < 0) {
                return false;
            }

            // Guard 2: minOpen can't drop below 0 (we can just treat '*' as empty string)
            if (minOpen < 0) {
                minOpen = 0;
            }
        }

        // Return true if minOpen reaches 0 (all '(' can be balanced)
        return minOpen == 0;
    }
}
