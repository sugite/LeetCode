class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if(grid.size()==0 || grid[0].size()==0) return 0;
        int m = grid.size() , n = grid[0].size();
        int res = 0;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j]=='1'){
                    ++res;
                    queue<int> q ;
                    q.push(i*n+j);
                    grid[i][j] = '0';
                    while(!q.empty()){
                        int index = q.front();
                        q.pop();
                        int x = index/n;
                        int y = index%n;
                        if(x+1<m&&grid[x+1][y]=='1'){
                            q.push((x+1)*n+y);
                            grid[x+1][y] = '0';
                        }
                        if(x-1>=0&&grid[x-1][y]=='1'){
                            q.push((x-1)*n+y);
                            grid[x-1][y] = '0';
                        }
                        if(y+1<n&&grid[x][y+1]=='1'){
                            q.push(x*n+y+1);
                            grid[x][y+1] = '0';
                        }
                        if(y-1>=0&&grid[x][y-1]=='1'){
                            q.push(x*n+y-1);
                            grid[x][y-1] = '0';
                        }
                    }
                }
            }
        }
        return res;
    }
};