#define MAXN 1050
int n =(9*9*9),m =(81+9*9+9*9+9*9);
int U[MAXN*MAXN];
int D[MAXN*MAXN];
int L[MAXN*MAXN];
int R[MAXN*MAXN];
int C[MAXN*MAXN]; //to see node[i] belong to which column
int row[MAXN*MAXN]; // to see node[i] belong to which row
int ans[MAXN],ansnum;
int nn[MAXN];
int mm[MAXN];
bool map1[MAXN][MAXN];
int head=0;
char str[100];
class Solution {
public:
    void read_data(){
        memset(mm,0,sizeof(mm));
        for(int i=1;i<=m;i++){
            R[i-1]=L[i+1]=U[i]=D[i]=i;
        }
        R[m]=0;
        R[head]=1;
        int id=m+1;
        int x,Rhead;
        for(int i=0;i<n;i++){
            Rhead=-1;
            for(int j=0;j<m;j++){
                if(map1[i][j]==true){
                    x=j+1;
                    mm[x]++;
                    row[id]=i;
                    C[id]=x;
                    //update the column
                    U[id]=U[x];
                    D[U[x]]=id;
                    U[x]=id;
                    D[id]=x;
                    //update the row
                    if(Rhead==-1){
                        L[id]=R[id]=id;
                        Rhead=id;
                    }
                    else {
                        L[id]=L[Rhead];
                        R[L[Rhead]]=id;
                        L[Rhead]=id;
                        R[id]=Rhead;
                    }
                    id++;
                }
            }
        }
    }
    
    void remove(int c){
        L[R[c]]=L[c];
        R[L[c]]=R[c];
        for(int i=D[c];i!=c;i=D[i]){
            for(int j=R[i];j!=i;j=R[j]){
                U[D[j]]=U[j];
                D[U[j]]=D[j];
                mm[C[j]]--;
            }
        }
    }
    
    void resume(int c){
        for(int i=U[c];i!=c;i=U[i]){
            for(int j=L[i];j!=i;j=L[j]){
                mm[C[j]]++;
                U[D[j]]=j;
                D[U[j]]=j;
            }
        }
        L[R[c]]=c;
        R[L[c]]=c;
    }
    
    bool dfs(int cur){
        if(R[head]==head){
            return true;
        }
        int s=999999999,c;
        for(int t=R[head];t!=head;t=R[t]){
            if(mm[t]<s){
                s=mm[t];
                c=t;
            }
        }
        remove(c);
        for(int i=D[c];i!=c;i=D[i]){
            ans[row[i]]=true;
            for(int j=R[i];j!=i;j=R[j]){
                remove(C[j]);
            }
            if(dfs(cur+1))return true;
            ans[row[i]]=false;
            for(int j=L[i];j!=i;j=L[j]){
                resume(C[j]);
            }
        }
        resume(c);
        return false;
    }
    
    void addrow(int i,int j,int k){
        int cur=(i*9+j)*9+k;
        map1[cur][i*9+j]=true;
        map1[cur][81+i*9+k]=true;
        map1[cur][81+81+j*9+k]=true;
        int rc=i/3;
        int lc=j/3;
        map1[cur][81+81+81+(rc*3+lc)*9+k]=true;
    }
    


    void solveSudoku(vector<vector<char>>& board) {
        memset(map1,false,sizeof(map1));
        for(int i = 0 ; i < 9 ; ++i){
            for(int j = 0 ; j < 9 ; ++j){
                if(board[i][j]=='.') for(int k=0;k<9;k++)addrow(i,j,k);
                else addrow(i,j,board[i][j]-'1');
            }
        }
        read_data();
        memset(ans,false,sizeof(ans));
        dfs(0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                for(int k=0;k<9;k++)
                if(ans[(i*9+j)*9+k])board[i][j]=k+1+'0';
            }
        }
    }
};