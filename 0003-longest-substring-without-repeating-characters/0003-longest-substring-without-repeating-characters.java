class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> seen = new HashSet<>();
        int l = 0;
        int ans = 0;
        for (int r = 0; r < s.length(); r++) {
            while (seen.contains(s.charAt(r))) {
                seen.remove(s.charAt(l));
                l++;
            }
            seen.add(s.charAt(r));
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
        /*
        HashMap<Character, Integer> map = new HashMap<>();
        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.length(); r++) {
            char curr = s.charAt(r);

            // Agar duplicate mila, toh 'l' ko direct aage jump karwao
            if (map.containsKey(curr)) {
                l = Math.max(l, map.get(curr) + 1);
            }

            // Map mein current character ka index update karo
            map.put(curr, r);

            // Answer update karo
            ans = Math.max(ans, r - l + 1);
        }

        return ans;
        */
    }
}
