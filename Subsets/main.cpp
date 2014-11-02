class Solution {
    vector<vector<int> > res ;
    vector<int> flag ;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        if(S.empty()) return res;
        flag.resize(S.size());
        myFunc(S , 0);
        return res ;
    }
    
    void myFunc(vector<int> &S , int n){
        if(n==S.size()){
            vector<int> temp ;
            for(int i = 0 ; i < n ; i++){
                if(flag[i]==1){
                    temp.push_back(S[i]);
                }
            }
            sort(temp.begin(),temp.end());
            res.push_back(temp);
            return ;
        }
        for(int i = 0 ; i < 2 ; i++){
            flag[n] = i;
            myFunc(S , n+1);
        }
    }
};
