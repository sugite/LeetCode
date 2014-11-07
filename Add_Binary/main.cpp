class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty()) return b;
        if(b.empty()) return a;
        int len = max(a.size(),b.size())+1;
        string res(len,'0');
        a = string(len-a.size()-1,'0') + a;
        b = string(len-b.size()-1,'0') + b;
        for(int i = len-2 ; i >=0 ; i--){
            int tmp = a[i]-'0' + b[i]-'0' + res[i+1] - '0' ;
            if(tmp==2) res[i+1] = '0' , res[i] = '1' ;
            else if(tmp==3) res[i+1] = '1' , res[i] = '1';
            else res[i+1] = tmp+'0';
        }
        if(res[0]=='0') return res.substr(1);
        return res ;
    }
};
