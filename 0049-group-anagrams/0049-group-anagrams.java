class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> entry = new HashMap<>();
        for (String s : strs) {
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String sortedKey = new String(chars);

            /*we could use
            entry.computeIfAbsent(sortedKey,k -> new ArrayList<>()).add(s);
            */
            if (!entry.containsKey(sortedKey)) {
                entry.put(sortedKey, new ArrayList<>());
            }
            entry.get(sortedKey).add(s);
        }
        return new ArrayList<>(entry.values());
    }
}
