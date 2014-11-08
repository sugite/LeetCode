class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0 ;
        vector<int> rec(s.size(),0);
        for(int i = s.size()-2 ; i >=0 ; i--){
            if(s[i]==')') {rec[i] = 0;continue;}
            int j = i + 1 + rec[i+1];
            if(j<s.size() && s[j]==')'){
                rec[i] = rec[i+1] + 2 ;
                if(j+1<s.size())
                    rec[i] += rec[j+1];
            }
            maxLen = max(maxLen,rec[i]);
        }
        return maxLen;
    }
};

//reference:https://leetcodenotes.wordpress.com/tag/1waydp/
