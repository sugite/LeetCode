#include<iostream>
#include<string>

using namespace std ;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()) return false ;
        if(s1.size()==0 && s2.size()==0 ) return true ;
        if(s1.size()== 0 ) return s3.compare(s2) == 0 ;
        if(s2.size()== 0 ) return s3.compare(s1) == 0 ;
//        if(s1[0]!=s3[0] && s2[0]!=s3[0]) return false ;
//        if(s1[0]==s3[0] && s2[0]!=s3[0]) return isInterleave(s1.substr(1,s1.size()-1),s2,s3.substr(1,s3.size()-1));
//        if(s1[0]!=s3[0] && s2[0]==s3[0]) return isInterleave(s1,s2.substr(1,s2.size()-1),s3.substr(1,s3.size()-1));
//        return isInterleave(s1.substr(1,s1.size()-1),s2,s3.substr(1,s3.size()-1)) || 
//                isInterleave(s1,s2.substr(1,s2.size()-1),s3.substr(1,s3.size()-1));
		bool dp[s1.length()+1][s2.length()+1];

	    for(int i=0; i<s1.length()+1; i++)
	        for(int j=0; j< s2.length()+1; j++){
	            if(i==0 && j==0)
	                dp[i][j] = true;
	            else if(i == 0)
	                dp[i][j] = ( dp[i][j-1] && s2[j-1] == s3[i+j-1]);
	            else if(j == 0)
	                dp[i][j] = ( dp[i-1][j] && s1[i-1] == s3[i+j-1]);
	            else
	                dp[i][j] = ( dp[i-1][j] && s1[i-1] == s3[i+j-1] ) || (dp[i][j-1] && s2[j-1] == s3[i+j-1] );
	        }
	    return dp[s1.length()][s2.length()];
    }
};

int main()
{
	string s1("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa");
	string s2("babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab");
	string s3("babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");
	Solution sol ;
	cout<<sol.isInterleave(s1,s2,s3)<<endl;
	return 0;
}
