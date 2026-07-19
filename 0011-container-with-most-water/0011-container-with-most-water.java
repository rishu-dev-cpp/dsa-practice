class Solution {
    public int maxArea(int[] heights) {
        int l = 0, r = heights.length - 1;
        int maxArea = 0;
        while (l < r) {
            int height = Math.min(heights[l], heights[r]);
            int length = r - l;
            maxArea = Math.max(maxArea, length * height);
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxArea;
    }
}
