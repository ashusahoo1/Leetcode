// 303. Range Sum Query - Immutable

class NumArray {
public:
    vector<int> ans;
    NumArray(vector<int>& nums) {
        ans.push_back(0);
        for(int num:nums){
            ans.push_back(ans.back()+num);
        }
    }
    
    int sumRange(int left, int right) {
        return ans[right+1]-ans[left];
    }
};
