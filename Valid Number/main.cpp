class Solution {
public:
    bool isNumber(string s) {
        s.erase(0,s.find_first_not_of(" "));  
        s.erase(s.find_last_not_of(" ") + 1);  
        bool p = false , e = false , n = false , be = false;
        //be表示e或者E后面是否有数字
        for(int i = 0 ; i < s.size() ; ++i){
            if(s[i]>='0' && s[i]<='9'){
                n = true;
                be = true;
            }else if(s[i]=='.'){
                if(e || p) return false;
                p = true;
            }else if(s[i]=='e' || s[i]=='E'){
                if(e || !n) return false;
                e = true;
                be = false;
            }else if(s[i]=='+' || s[i]=='-'){
                if(i!=0 && s[i-1]!='e' && s[i-1]!='E') return false;
            }else return false;
        }
        return n && be;
    }
};