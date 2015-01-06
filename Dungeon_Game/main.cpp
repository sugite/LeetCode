class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
        int n = dungeon.at(0).size();
        
        vector<vector<int> > dp(dungeon);
        dp[m-1][n-1] = max(1,1 - dp[m-1][n-1]) ;
        for(int i = n-2 ; i >=0 ; --i){
            dp[m-1][i] = max(dp[m-1][i+1] - dp[m-1][i] , 1);
        }
        for(int i = m-2 ; i >=0 ; --i){
            dp[i][n-1] = max(dp[i+1][n-1] - dp[i][n-1] , 1);
        }
        if(m<2||n<2) return dp[0][0];
        
        for(int i = m-2 ; i >= 0 ; --i){
            for(int j = n-2 ; j >= 0 ; --j){
                dp[i][j] = min(max(dp[i+1][j] - dp[i][j],1),max(dp[i][j+1] - dp[i][j],1));
            }
        }
        return dp[0][0];
    }
};