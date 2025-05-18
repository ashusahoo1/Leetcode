//2855. Minimum Right Shifts to Sort the Array

class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int ind = 0;
        int n = nums.size();
// first incresing part if it reacher end its already sorted
        while (ind + 1 < n && nums[ind] < nums[ind + 1]) {
            ind++;
        }

        if (ind == n - 1)
            return 0;
// for second incresing part, very cool!!
        ind++;
        int pivot = ind;
        while (ind + 1 < n && nums[ind] < nums[ind + 1])
            ind++;
        if (ind != n - 1)
            return -1;
        if (nums[pivot] < nums[0] && nums[n - 1] < nums[0]) {
            return n - pivot;
        } else
            return -1;
    }
};
