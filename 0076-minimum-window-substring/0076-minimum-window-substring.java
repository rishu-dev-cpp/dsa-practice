class Solution {
    public String minWindow(String s, String t) {
        // Edge Case: Agar 't' bada hai 's' se, toh substring mil hi nahi sakti
        if (t.length() > s.length()) return "";

        // 1. 't' ke har character ki frequency Map mein dalo
        Map<Character, Integer> countT = new HashMap<>();
        for (char c : t.toCharArray()) {
            countT.put(c, countT.getOrDefault(c, 0) + 1);
        }

        // Window mein kitne characters aaye, unko track karne ke liye Map
        Map<Character, Integer> window = new HashMap<>();

        // 'need' = Kitni unique categories (characters) satisfy karni hain
        int need = countT.size();
        // 'have' = Abhi tak kitni unique categories satisfy ho chuki hain
        int have = 0;

        // Result store karne ke liye
        int minLen = Integer.MAX_VALUE;
        int resL = -1, resR = -1; // Minimum window ke Left aur Right indices

        int l = 0;

        // 2. Sliding Window (Expand Right)
        for (int r = 0; r < s.length(); r++) {
            char c = s.charAt(r);

            // Current character ko window map mein add karo
            window.put(c, window.getOrDefault(c, 0) + 1);

            // Check karo: Kya 'c' category ki required quantity poori ho gayi?
            if (countT.containsKey(c) && window.get(c).equals(countT.get(c))) {
                have++; // Category Complete â
            }

            // 3. Jab saari categories complete ho jayein (have == need), TAB SHRINK KARO!
            while (have == need) {
                // Minimum window size update karo
                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    resL = l;
                    resR = r;
                }

                // Left element ko window se bahar nikalo
                char leftChar = s.charAt(l);
                window.put(leftChar, window.get(leftChar) - 1);

                // Agar nikalne ke baad requirement toot gayi, toh 'have' kam karo
                if (countT.containsKey(leftChar) && window.get(leftChar) < countT.get(leftChar)) {
                    have--; // Category Incomplete â
                }

                l++; // Window left se tight karo
            }
        }

        // Agar minLen update hi nahi hui matlab valid window mili nahi
        return minLen == Integer.MAX_VALUE ? "" : s.substring(resL, resR + 1);
    }
}