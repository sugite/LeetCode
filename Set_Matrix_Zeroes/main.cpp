class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty()||matrix[0].empty()) return ;
        int row = -1 , col = -1 ;
        for(int i = 0 ; i < matrix.size(); i++){
            for(int j = 0 ; j < matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    if(i==0) row = 0;
                    if(j==0) col = 0;
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }
        for(int i = 1 ; i < matrix.size() ; i++){
            if(matrix[i][0]==0){
                matrix[i].assign(matrix[0].size(),0);
            }
        }
        for(int j = 1 ; j < matrix[0].size() ; j++){
            if(matrix[0][j]==0){
                for(int i = 0 ; i < matrix.size() ; i++){
                    matrix[i][j] = 0 ;
                }
            }
        }
        if(row==0){
            matrix[0].assign(matrix[0].size(),0);
        }
        if(col==0){
            for(int i = 0 ; i < matrix.size() ; i++){
                matrix[i][0] = 0 ;
            }
        }
    }
};
