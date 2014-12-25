class Solution {
public:
    string convertToTitle(int n) {
        if(n<1) return NULL;
        vector<int> mo;
        while(n){
            mo.push_back((n-1)%26);
            n = (n-1)/26;
        }
        string ret = "";
        for(int i = mo.size()-1 ; i>=0 ; i--)
            ret += (char)(mo[i]+'A');
        return ret ;
    }
};