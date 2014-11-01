class Solution {
public:
    void sortColors(int A[], int n) {
        int i = -1 , j = n ;
        for(int index = 0 ; index < j ; ){
            if(A[index]==2){
                A[index] = A[--j];
                A[j] = 2 ;
                continue;
            }
            if(A[index]==0){
                A[index] = A[++i];
                A[i] = 0 ;
            }
            index++;
        }
    }
};
