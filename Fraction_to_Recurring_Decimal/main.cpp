class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if(numerator==0) return "0";
        string ret = "";
        if(numerator<0 ^ denominator<0)
            ret += "-";
        long long a = abs(numerator) , b = abs(denominator);
        ret += to_string(a/b);
        a %= b ;
        if(a==0) return ret ;
        ret += ".";
        unordered_map<long long,long long> m ;
        m[a] = 0 ;
        long long i = 0 ;
        string str = "" ;
        while(a){
            a *= 10 ;
            str += to_string(a/b) ;
            a %= b;
            if(m.find(a) == m.end()) m[a] = ++i;
            else break;
        }
        if(a==0) return ret + str ;
        return ret + str.substr(0,m[a]) + "(" + str.substr(m[a]) + ")";
        
    }
};