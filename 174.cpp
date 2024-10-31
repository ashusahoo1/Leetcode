// 174. Dungeon Game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
       int m = dungeon[0].size();
       int n = dungeon.size();
       vector<vector<int>> dp(n+1,vector<int>(m+1,1e5));
       dp[n-1][m]=1;
       dp[n][m-1]=1;
         for(int i =  n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int val = min(dp[i][j+1],dp[i+1][j]) - dungeon[i][j];
                if(val>0) dp[i][j]=val;
                else dp[i][j]=1;
            }
         }
         return dp[0][0];
    }
};
