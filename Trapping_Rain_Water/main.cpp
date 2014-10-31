class Solution {
public:
    int trap(int A[], int n) {
        int a=0;
        int b=n-1;
        int Max=0;
        int leftmax=0;
        int rightmax=0;
        while(a<=b){
            leftmax=max(leftmax,A[a]);
            rightmax=max(rightmax,A[b]);
            if(leftmax<rightmax){
                Max+=(leftmax-A[a]);      
                a++;
            }
            else{
                Max+=(rightmax-A[b]);
                b--;
            }
        }
        return Max;
    }
};
