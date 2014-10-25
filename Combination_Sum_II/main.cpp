class Solution {
public:
    vector<vector<int> > res ;
    set<vector<int> > s ;
    int C ;
    int *flag ;
    int count = 0 ;
    int tag ;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        if(num.empty()) return res ;
        sort(num.begin(),num.end());
        C = num.size();
        flag = new int[C];
        tag = target ;
        fun(0,num);
        delete flag ;
        for(set<vector<int> >::iterator iter = s.begin();iter!=s.end();iter++){
            res.push_back(*iter);
        }
        return res ;
    }
    
    void fun(int n,vector<int> &num){
        if(n==C){
            if(count==tag){
                vector<int> temp ;
                for(int i = 0 ; i < C ; i++){
                    if(flag[i]==1)
                        temp.push_back(num[i]);
                }
                s.insert(temp);
            }
        }else{
            flag[n] = 0;
            fun(n+1,num);
            if(count+num[n]<=tag){ //要剪枝，不然会超时
                flag[n] = 1;
                count+=num[n];
                fun(n+1,num);
                count-=num[n];
            }
        }
    }
};
