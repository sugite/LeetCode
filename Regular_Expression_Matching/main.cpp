class Solution {
public:
    bool matchStar(char c , const char *s,const char *p){
        do{
            if(isMatch(s,p)) return true;
        }while(s[0]!='\0'&&(*s++==c||c=='.'));
        return false;
    }
    bool isMatch(const char *s, const char *p) {
        if(p[0]=='\0'&&s[0]=='\0') return true;
        if(p[0]=='\0'&&s[0]!='\0') return false;
        if(p[1]=='*') return matchStar(p[0],s,p+2);
        if((p[0]=='.'&&s[0]!='\0') || s[0]==p[0]) return isMatch(s+1,p+1);
        return false;
    }
};
