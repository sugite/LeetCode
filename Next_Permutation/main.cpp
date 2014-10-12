class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()<2) return ;
        int descPos;
        for(descPos = num.size()-2;descPos>=0;descPos--){
            if(num[descPos]<num[descPos+1])
                break;
        }
        int swapPos;
        for(swapPos = num.size()-1;swapPos>descPos;swapPos--){
            if(num[swapPos]>num[descPos])
                break;
        }
        int temp = num[descPos];
        num[descPos] = num[swapPos];
        num[swapPos] = temp ;
        int len = (num.size()-1+(descPos+1))/2;
        int sum = num.size()-1+(descPos+1) ;
        for(int i = descPos + 1 ; i<=len ; ++i){
            temp = num[i];
            num[i] = num[sum-i];
            num[sum-i] = temp;
        }
    }
};
