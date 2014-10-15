class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1) ;
        for(int i = 0 ; i <= rowIndex/2 ; ++i ){
            res[i] = c(rowIndex,i);
        }
        for(int i = rowIndex ; i >rowIndex/2 ; i--){
            res[i] = res[rowIndex - i];
        }
        return res;
    }
    
    int c(int n,int k){
        if(k==0) return 1 ;
        int up = 1 ;
        int down = 1 ;
        int fator = 1;
        for(int i = 0 ; i < k ; i++){
            up*= (n-i);
            down*= (k-i);
            fator = gcd(up,down);
            up/=fator;
            down/=fator;
        }
        return up/down ;
    }
    
    int gcd(int a , int b ){
        if(b==0) return a ;
        return gcd(b,a%b);
    }
};
