/* Worst Case N^2
class Solution {
    public String reverseParentheses(String s) {
        Stack<Character> stack = new Stack<>();
        
        for (char c : s.toCharArray()) {
            if (c == ')') {
                // 1. '(' tak pop karke reverse string banao
                StringBuilder sb = new StringBuilder();
                while (stack.peek() != '(') {
                    sb.append(stack.pop());
                }
                
                // 2. '(' ko hatao
                stack.pop();
                
                // 3. Reversed string ko wapas stack me daalo
                for (int i = 0; i < sb.length(); i++) {
                    stack.push(sb.charAt(i));
                }
            } else {
                // Normal character ya '(' ko stack me daalo
                stack.push(c);
            }
        }
        
        // Final result nikalna
        StringBuilder res = new StringBuilder();
        while (!stack.isEmpty()) {
            res.append(stack.pop());
        }
        return res.reverse().toString();
    }
}*/

// Teleportation Jutsu ~Minato ð
class Solution {
    public String reverseParentheses(String s) {
        int n = s.length();
        int[] pair = new int[n];
        Stack<Integer> stack = new Stack<>();
        
        // Pass 1: Find matching bracket pairs - O(N)
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else if (s.charAt(i) == ')') {
                int openIndex = stack.pop();
                pair[openIndex] = i;
                pair[i] = openIndex;
            }
        }
        
        // Pass 2: Wormhole Traversal - O(N)
        StringBuilder result = new StringBuilder();
        int dir = 1; // 1 = Left-to-Right, -1 = Right-to-Left
        
        for (int curr = 0; curr < n; curr += dir) {
            if (s.charAt(curr) == '(' || s.charAt(curr) == ')') {
                curr = pair[curr]; // Teleport to matching bracket
                dir = -dir;        // Flip direction
            } else {
                result.append(s.charAt(curr));
            }
        }
        
        return result.toString();
    }
}