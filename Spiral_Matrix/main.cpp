class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<int> res ;
        int row = matrix.size();
        if(row==0) return res ;
        int col = matrix[0].size();
        int x = 0 , y = 0;
        int index = 0 ;
        for(int i = 0 ; i < row*col ; i++){
            res.push_back(matrix[x][y]) ;
            matrix[x][y] = -10 ;
            if(x+dir[index][0]>=row||x+dir[index][0]<0 || \
               y+dir[index][1]>=col||y+dir[index][1]<0 || \
               matrix[x+dir[index][0]][y+dir[index][1]]==-10)
                index = (index+1)%4;
            x = x+dir[index][0];
            y = y+dir[index][1];
        }
        return res;
    }
};
