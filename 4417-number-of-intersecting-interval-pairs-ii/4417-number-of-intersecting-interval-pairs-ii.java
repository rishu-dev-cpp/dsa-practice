class Solution {
    public long countIntersectingIntervals(int[][] intervals) {
        int n = intervals.length;
        
        // 1. Sabhi intervals ke END points ko alag array me extract karte hain
        int[] ends = new int[n];
        for (int i = 0; i < n; i++) {
            ends[i] = intervals[i][1];
        }
        
        // 2. Binary search lagane ke liye END points ko sort kar dete hain
        Arrays.sort(ends);
        
        long nonIntersectingPairs = 0;
        
        // 3. Har interval ke liye non-intersecting pairs ginte hain
        for (int[] interval : intervals) {
            int start = interval[0];
            
            // `start` se strictly chhote kitne `end` points hain?
            int count = binarySearchCount(ends, start);
            nonIntersectingPairs += count;
        }
        
        // 4. Total possible pairs formula: N * (N - 1) / 2
        long totalPairs = (long) n * (n - 1) / 2;
        
        // 5. Intersecting = Total - Non-Intersecting
        return totalPairs - nonIntersectingPairs;
    }
    
    // Custom Binary Search Helper Function
    // Ye function return karta hai ki `ends` array me `target` se STRICTLY CHHOTE (< target) kitne elements hain
    private int binarySearchCount(int[] arr, int target) {
        int low = 0, high = arr.length;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] < target) {
                // Agar mid element target se chhota hai, to mid ke left wale sabhi elements bhi target se chhote honge
                low = mid + 1;
            } else {
                // Agar arr[mid] >= target hai, to range ko left me narrow karo
                high = mid;
            }
        }
        
        // Loop khatam hone par `low` wahi index hoga jitne elements target se strictly chhote hain
        return low;
    }
}