//2859. Sum of Values at Indices With K Set Bits

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {

        int index = 0;
        int sum = 0;
       

        for (int n : nums) {
            int bits = countSetBits(index++);
            if (bits == k) {
                sum += n;
            }
        }
        return sum;
    };

private:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {

            count += n % 2;
            n /= 2;
        }
        return count;
    }

};
