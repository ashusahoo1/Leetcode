// 1217. Minimum Cost to Move Chips to The Same Position


class Solution {
public:
    int help(vector<int>&vec, int key)
    {
        int cnt = 0;
        for(auto val:vec)
            if(val%2 == key) cnt++;
        return cnt;
    }
    int minCostToMoveChips(vector<int>& position) 
    {
        int ans1 = help(position, 0);
        int ans2 = help(position, 1);
        return min(ans1, ans2);
    }
};
