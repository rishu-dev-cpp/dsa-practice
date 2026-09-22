class Solution {
    public boolean isHappy(int n) {
        Set<Integer> ayah = new HashSet<>();

        while (!ayah.contains(n)) {
            ayah.add(n);
            n = help(n);
            if (n == 1) {
                return true;
            }
        }
        return false;
    }
    private int help(int n) {
        int ans = 0;
        while (n > 0) {
            int digi = n % 10;
            ans += digi * digi;
            n /= 10;
        }
        return ans;
    }
}
