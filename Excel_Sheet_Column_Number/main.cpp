class Solution {
public:
    int titleToNumber(string s) {
        if(s.empty()) return 0;
        int ret = 0 ;
        for(int i = s.size()-1 , j = 0 ; i>=0 ; i--,j++){
            ret += (s[i]-'A'+1)*((int)pow(26,j));
        }
        return ret ;
    }
};