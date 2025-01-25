


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int numsLength = nums.size();
        // initialize the cursor
        int i = 0;

        // phase 1: sort the numbers with cyclic sort
        // move the cursor through the entire list
        while (i < numsLength) {
            int valAtI = nums[i];

            // does the value belong in the range of the list?
            // if it doesn't, we get an out of bounds error
            // when we try to access nums[valAtI] later
            bool belongsInRange = valAtI < numsLength;

            if (belongsInRange && valAtI != nums[valAtI]) {
                swap(nums[i], nums[valAtI]);
            } else {
                // move the cursor to the next index
                i++;
            }
        }

        // phase 2: find the missing number
        for (int x = 0; x < numsLength; x++) {
            if (x != nums[x]) {
                return x;
            }
        }

        // if all the numbers are already present,
        // the missing number is the length of the list
        return numsLength;
    }
};
