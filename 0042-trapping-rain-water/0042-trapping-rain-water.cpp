class Solution {
public:
    int trap(vector<int>& height) {
       /* int n = height.size();
        
        vector<int> left(n), right(n);

        left[0] = height[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1], height[i]);
        }
        int total = 0;
        for(int i=0;i<n;i++){
            total += min(left[i], right[i]) - height[i];
        }
        return total; */
        int n = height.size();
        int left = 0, right = n - 1, leftMax = 0, rightMax = 0, total = 0;
        while(left<right){
            if(height[left]<=height[right]){
                leftMax = max(leftMax, height[left]);
                total += leftMax-height[left];
                left++;
            }else {
                rightMax = max(rightMax, height[right]);
                total += rightMax-height[right];
                right--;
            }
        }return total;
    }
};