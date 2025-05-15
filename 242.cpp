

// 242. Valid Anagram

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) {
            return false;
        }
        vector<int> mp1(26, 0), mp2(26, 0);

        for (int i = 0; i < s.size(); i++) {
            mp1[s[i] - 'a']++;
            mp2[t[i] - 'a']++;
        }

        for(int i =0;i<s.size();i++){
            if(mp1[i]!=mp2[i]){
                return false;
            }
           
        }
 return true;
    }
};
