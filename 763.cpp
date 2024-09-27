//763. Partition Labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            end = max(end, lastIndex[s[i] - 'a']);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};
