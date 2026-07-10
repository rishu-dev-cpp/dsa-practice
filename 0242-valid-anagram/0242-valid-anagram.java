class Solution {
    public boolean isAnagram(String s, String t) {

        if(s.length() != t.length()){
            return false;
        }
        
        int[] arr = new int[26];
        
        for(int i = 0; i< s.length(); i++){
            char c = s.charAt(i);
            arr[c-'a']++;
            char k = t.charAt(i);
            arr[k-'a']--;

        }

        for(int x : arr){
            if(x != 0){
                return false;
            }
        }
        return true;
    }
}