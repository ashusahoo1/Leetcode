// 888. Fair Candy Swap


class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sm1 = 0;
        int sm2 = 0;
        for(int s : aliceSizes) {
            sm1+=s;
        }
        
        int mpp[100000+4];
        memset(mpp, 0, sizeof(mpp));
        for(int s : bobSizes) {
            sm2+=s;
            mpp[s]++;
        }
        
        int sm = (sm2 + sm1);
        if((sm%2) == 1) {
            return {};
        }
        
        sm/=2;
        
        for(int s : aliceSizes) {
            int new_alice_sm = sm1 - s;
            if(new_alice_sm >= sm) {
                continue;
            }
            
            int extra_wt_needed = sm - new_alice_sm;
            if(extra_wt_needed > (1e5)) {
                continue;
            }
            if(mpp[extra_wt_needed] != 0) {
                return {s, extra_wt_needed};
            }
        }
        
        return {};
    }
};
