//70. Climbing Stairs


// PRACTICE:1

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) {
            return n;
        }
        int prev1 = 3;
        int prev2 = 2;
        int curr = 0;

        for (int i = 3; i < n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
