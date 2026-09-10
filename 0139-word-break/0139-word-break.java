/*
Path 1: Single "a" lete gaye
idx=0 ('a') -> idx=1 ('a') -> idx=2 ('a') -> idx=3 ('a') -> idx=4 ('a') -> idx=5 ('b') [FAIL!]

Unwinding (Saving Dead Ends):
- dp[5] = false
- dp[4] = false
- dp[3] = false
- dp[2] = false  <-- [CRITICAL DEAD END SAVED AT INDEX 2]
- dp[1] = false

Path 2: Back at idx=0, now trying "aa"
idx=0 par "aa" liya -> Calls recur(end = 2)

Child Call (idx = 2):
1. First line runs: if (dp[2] != null) return dp[2];
2. Code finds dp[2] == false!
3. INSTANT RETURN false in O(1) time without running loop or cutting substrings!
*/
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        // 1. Fast lookup ke liye HashSet me convert kiya
        Set<String> wordSet = new HashSet<>(wordDict);
        
        // 2. Boolean[] (Wrapper Class) for 3-State DP Array: null, true, false
        Boolean[] dp = new Boolean[s.length() + 1];
        
        return recur(0, s, wordSet, dp);
    }

    private boolean recur(int idx, String s, Set<String> wordSet, Boolean[] dp) {
        // Base Case: String ke end tak successfully pahunch gaye
        if (idx == s.length()) return true;

        // Memoization Check: Agar is index se aage ka answer pehle se pata hai
        if (dp[idx] != null) return dp[idx];

        // Current 'idx' se start hone wale saare possible prefixes try karo
        for (int end = idx + 1; end <= s.length(); end++) {
            String prefix = s.substring(idx, end);

            // Short-Circuiting: Prefix set me hai AND baaki string bhi valid break ho sakti hai
            if (wordSet.contains(prefix) && recur(end, s, wordSet, dp)) {
                return dp[idx] = true; // Save success & return true
            }
        }

        // Agar saare prefixes fail ho gaye, to is index ko Dead End (false) mark karo
        return dp[idx] = false;
    }
}