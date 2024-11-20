//645. Set Mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> unqNums;
        vector<int> res;
        for(auto num : nums){
            if(unqNums.count(num)){
                res.push_back(num);
            }
            unqNums.insert(num);
        }
        for(int num = 1; num <= nums.size(); num++){
            if(!unqNums.count(num))res.push_back(num);
        }
        return res;
    }
};
