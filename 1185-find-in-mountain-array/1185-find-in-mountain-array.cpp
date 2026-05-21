/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int low = 0, high = n-1;
        while(low<high){
            int mid = low + (high - low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                low = mid + 1;
            }else high = mid;
        }
        int peak = low;

        // Left side searching ....
        low = 0;
        high = peak;
        while(low <= high){
            int mid = low + (high-low)/2;
            int val = mountainArr.get(mid);
            if (val == target) return mid;// phle hi chotu mil gya
            else if (val < target) low = mid + 1;
            else high = mid - 1;
        }
        // Right side searching ....
        low = peak +1;
        high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int val = mountainArr.get(mid);
            if (val == target) return mid;// aise bhi phle wo left wala chalega to ye baad me hi ayega to isliye min index to already mil chuka rhega
            else if (val > target) low = mid + 1;
            else high = mid - 1;
        }

        return -1;
    }
};