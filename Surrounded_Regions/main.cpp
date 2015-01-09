class Solution {
public:
    class Point{
    public :
        Point(int x,int y):a(x),b(y){}
        int a , b;
    };


    void solve(vector<vector<char> > &board) {
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();
        if(n==0) return ;
        
        vector<vector<char> > tmp(m+2,vector<char>(n+2,'O'));
        for(int i = 1 ; i <= m ; ++i){
            for(int j = 1 ; j <=n ; ++j){
                tmp[i][j] = board[i-1][j-1];
            }
        }
        
        list<Point> lst ;
        lst.push_back(Point(0,0));
        tmp[0][0] = 'X';
        while(!lst.empty()){
            Point p = lst.front();
            lst.pop_front();
            int x = p.a, y = p.b;
            if(x-1>=0&&tmp[x-1][y]=='O'){
                lst.push_back(Point(x-1,y));
                tmp[x-1][y]='X';
            }
            if(y-1>=0&&tmp[x][y-1]=='O'){
                lst.push_back(Point(x,y-1));
                tmp[x][y-1]='X';
            }
            if(x+1<m+2&&tmp[x+1][y]=='O'){
                lst.push_back(Point(x+1,y));
                tmp[x+1][y]='X';
            }
            if(y+1<n+2&&tmp[x][y+1]=='O'){
                lst.push_back(Point(x,y+1));
                tmp[x][y+1]='X';
            }
        }
        
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(tmp[i+1][j+1]=='O')
                    board[i][j] = 'X';
            }
        }
    }
};