class Solution {
public:
    vector< vector<int> > res ;
    int num ;
    int count ;
    vector<int> temp;
    vector<vector<int> > combine(int n, int k) {
        if(n==0) return res ;
        if(n==1 && k==1){
            vector<int> a(1,1);
            res.push_back(a);
            return res ;
        } 
        num = n ;
        count = k;
        temp.resize(n);
        fun(0,0);
        return res ;
    }
    
    void fun(int n,int k){
        if(n==num){
            if(k==count){
                vector<int> t(0,0);
                for(int i = 0 ; i < n; ++i)
                    if(temp[i]==1)
                        t.push_back(i+1);
                res.push_back(t);
            }
            return ;
        }
        for(int i = 0 ; i < 2 ; ++i){
            temp[n] = i;
            k+=i;
            fun(n+1,k);
            k-=i;
        }
    }
};
