class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.size();
        int n = T.size();
        if(m<n) return 0;
        vector< vector<int> > dist(n+1,vector<int>(m+1,0));
        for(int i = 0 ; i <= m ; ++i){dist[0][i] = 1 ;}
        for(int i = 1 ; i <=n ; ++i){
            for(int j = 1 ; j <=m ; ++j){
                dist[i][j] = dist[i][j-1] + (S[j-1]==T[i-1]?dist[i-1][j-1]:0);
            }
        }
        return dist[n][m];
    }
};
