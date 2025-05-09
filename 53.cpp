// 53.maximum subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int res = nums[0];
       int total=0;

       for(int n: nums)
       // for every integer n in array num
       {
        if(total<0){
            total=0;
        }
        total+=n;
        res= max(res,total);
       }   
       return res;   
    }
};
