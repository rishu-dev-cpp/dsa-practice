class Solution {
    public int findNumbers(int[] nums) {
        int evenDigit = 0;
        for(int num: nums){
            int count = (int)Math.floor(Math.log10(num))+1;
            if(count%2==0){
                evenDigit++;
            }
        }return evenDigit;
    }
}