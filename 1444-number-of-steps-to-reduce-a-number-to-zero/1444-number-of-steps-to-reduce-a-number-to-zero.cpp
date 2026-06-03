class Solution {
public:
    int numberOfSteps(int num) {
         if (num == 0) {
            return 0;
        }
        // 2. Recursive Case: If even, divide by 2. If odd, subtract 1.
        if (num % 2 == 0) {
            return 1 + numberOfSteps(num / 2);
        } else {
            return 1 + numberOfSteps(num - 1);
        }
    }
};