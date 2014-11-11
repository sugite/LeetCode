class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        map<char,char> m;
        m[')'] = '(' , m[']'] = '[' , m['}'] = '{' ; 
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                stk.push(s[i]);
            else if(m.find(s[i])!=m.end()){
                if(!stk.empty() && m[s[i]]==stk.top()) stk.pop();
                else return false;
            }else{
                return false;
            }
        }
        return stk.empty();
    }
};
