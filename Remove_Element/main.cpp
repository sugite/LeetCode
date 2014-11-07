class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0 , tail = n - 1;
        while(i<=tail){
            if(A[i] == elem) A[i] = A[tail--];
            else i++;
        }
        return tail+1;
    }
};
