class Solution {
    public boolean checkInclusion(String s1, String s2) {
        /*
        if (s1.length() > s2.length()) {
            return false;
        }

        int[] s1Count = new int[26];
        int[] s2Count = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1.charAt(i) - 'a']++;
            s2Count[s2.charAt(i) - 'a']++;
        }
        if (Arrays.equals(s1Count, s2Count)) return true;

        for (int i = s1.length(); i < s2.length(); i++) {
            // Using maths

            s2Count[s2.charAt(i) - 'a']++;
            s2Count[s2.charAt(i - s1.length()) - 'a']--;
            if (Arrays.equals(s1Count, s2Count)) return true;
            
        }
        return false;
        */
        if (s1.length() > s2.length())
            return false;

        int[] s1Count = new int[26];
        int[] s2Count = new int[26];

        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1.charAt(i) - 'a']++;
        }

        if (Arrays.equals(s1Count, s2Count))
            return true;

        int l = 0;
        for (int r = 0; r < s2.length(); r++) {
            s2Count[s2.charAt(r) - 'a']++;

            while (r - l + 1 > s1.length()) {
                s2Count[s2.charAt(l) - 'a']--;
                l++;
            }

            if (r - l + 1 == s1.length()) {
                if (Arrays.equals(s1Count, s2Count)) {
                    return true;
                }
            }
        }

        return false;
    }
}
