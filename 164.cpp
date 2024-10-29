//164. Maximum Gap

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int hi = 0, lo = INT_MAX, ans = 0;
        for (int n : nums) {
            hi = max(hi, n);
            lo = min(lo, n);
        }

        int bsize = max(1, (hi - lo) / (int(nums.size()) - 1));
        int numBuckets = (hi - lo) / bsize + 1;
        vector<vector<int>> buckets(numBuckets);

        for (int n : nums) {
            int idx = (n - lo) / bsize;
            buckets[idx].push_back(n);
        }

        int currhi = 0;
        for (auto& b : buckets) {
            if (b.empty()) continue;
            int prevhi = currhi ? currhi : b[0], currlo = b[0];

            for (int n : b) {
                currhi = max(currhi, n);
                currlo = min(currlo, n);
            }

            ans = max(ans, currlo - prevhi);
        }

        return ans;
    }
};
