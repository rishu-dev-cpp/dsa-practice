class Solution {
    public int[] twoSum(int[] numbers, int target) {
        /*
        int n = numbers.length;
        for(int i = 0; i<n;i++){
            for(int j = i+1; j < n;j++){
                if(numbers[i]+numbers[j] == target){
                    return new int[]{i+1, j+1};
                }
            }
        }
        return new int[]{};
        */
        int left = 0, right = numbers.length - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                return new int[] { left + 1, right + 1 };
            } else if (numbers[left] + numbers[right] < target) {
                left++;
            } else
                right--;
        }
        return new int[] {};
    }
}
