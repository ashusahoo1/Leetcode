// 371. Sum of Two Integers


class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int tmp = (a & b) << 1; // carry calculation
            a = a ^ b; // sum without carry
            b = tmp; // carry shifted left
        }
        return a;
    }
};
