class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int m = num1.size();
        int n = num2.size();
        vector<int> ans(m+n,0);
        for ( int i = m-1; i >= 0; i-- ) {
            for ( int j = n-1; j >= 0; j-- ) {
                ans[m+n-i-j-2] += (num1[i]-'0')*(num2[j]-'0');
                ans[m+n-i-j-1] += ans[m+n-i-j-2]/10;
                ans[m+n-i-j-2] %= 10;
            }
        }
        for ( int i = m+n-1; i >= 0; i-- ) {
            if ( ans[i] != 0 ) {
                for ( int j = i; j >= 0; j-- )
                    res += (ans[j]+'0');
                return res;
            }
        }
        return "0";
    }
};
