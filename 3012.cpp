//3012. Minimize Length of Array Using Operations


class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        // find the min element
        int mini = *min_element(nums.begin(), nums.end());
        int minCount = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            // keep a count of mini
            if(nums[i] == mini)
                minCount++;

            // if nums[i] is not a multiple of mini
            else if(nums[i] % mini != 0)
                return 1;
        }

        // if a num < mini wasn't been found through operations
        // then the length of final array is ceil(minCount/2)
        return (minCount + 1) / 2;
    }
};
