class Solution {
public:
    int C ;
    int *b ;
    vector<vector<string> > res ;
    vector<vector<string> > solveNQueens(int n) {
        C = n ;
        b = new int[C];
        Queen(0);
        return res ;
    }
    
    bool place(int k) {  
        for (int j = 0; j < k; j++)  
            if ((abs(k - j) == abs(b[j] - b[k])) || (b[j] == b[k]))  
                return false;  
        return true;  
    }  
  
    void Queen(int n) {  
        if (n == C){
            vector<string> str;
            string s(C,'.') ;
            for(int i = 0 ; i < C ; i++){
                s[b[i]] = 'Q';
                str.push_back(s);
                s[b[i]] = '.';
            }
            res.push_back(str);
        }else {  
            for (int i = 0; i < C; i++) {  
                b[n] = i;  
                if (place(n))  
                    Queen(n + 1);  
            }  
        }  
    }  
};
