class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[] ) {
        
        //base case
        if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        
        int number = digit[index] - '0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);
            output.pop_back();/*empty the output so that u can add another character like for 23  first we 
            replace 2 with a and 3 with d after 3 is replaced with d.
            index is again increase now index becomes 2 which is equal to length of digit 23 so the output is pushed
            into ans array and return to previous recursion, d is popped e is placed in then again e is popped ou f is placed 
            then everything is popped out 2 is replaced with b and same process goes on*/
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};
