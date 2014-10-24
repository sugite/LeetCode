class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0) return 0;
        if(s[0]=='0') return 0;
        if(s.size()==1 && s[0]!='0') return 1 ;
        
        // if(s[0]=='0') return numDecodings(s.substr(1));
        // if(s[1]=='0') return numDecodings(s.substr(2));
        // if(s[0]>='1'&&s[0]<='2'&&s[1]<='6') return numDecodings(s.substr(1))+numDecodings(s.substr(2));
        // return numDecodings(s.substr(1));
        
        int n = s.length();
        vector<int> count(n+1, 0);
        count[0] = 1;
        count[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            if('1' <= s[i-1] && s[i-1] <= '9')
                count[i] = count[i-1];
            if(s[i-2]>='1'&&atoi(s.substr(i-2,2).c_str())<=26)
                count[i] += count[i-2];
        }
        return count[n];
    }
};
