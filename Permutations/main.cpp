class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());  
        vector< vector<int> > res ;
        if(num.size()<2){ 
            res.push_back(num);
            return res ;
        }
        vector<int> temp(num) ;
        while(!temp.empty()){
            res.push_back(temp);
            temp = nextPermutation(temp);
        }
        return res;
    }
    
    vector<int> nextPermutation(vector<int> &num1) {
        vector<int> num(num1);
        if(num.size()<2) return num;
        int descPos;
        int flag = 0;
        for(descPos = num.size()-2;descPos>=0;descPos--){
            if(num[descPos]<num[descPos+1]){
                flag = 1 ;
                break;
            }
        }
        if(flag==0){
            num.clear();
            return num;
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
        return num;
    }
};
