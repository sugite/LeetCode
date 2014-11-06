class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > path(m+1,vector<int>(n+1,1));
        for (int i=2; i<=m; i++)
            for (int j=2; j<=n; j++)
                path[i][j]=path[i-1][j]+path[i][j-1];
        return path[m][n];
    }
};
