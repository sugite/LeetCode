class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s ;
        int maxLen = 1 ;
        int start = 0;
        for(int i = 0 ; i < s.size() ; ++i){
            int mid = i;
            int len = 1 ;
            int step = 1 ;
            while(mid-step>=0&&mid+step<s.size()&&s[mid-step]==s[mid+step]){
                len += 2;
                step++;
            }
            if(len>maxLen){
                maxLen = len ;
                start = mid-step+1;
            }
        }
        for(int i = 0 ; i < s.size()-1 ; ++i){
            int left = i;
            int right = i+1;
            if(s[left]==s[right]){
                int len = 2 ;
                int step = 1 ;
                while(left-step>=0&&right+step<s.size()&&s[left-step]==s[right+step]){
                    len += 2;
                    step++;
                }
                if(len>maxLen){
                    maxLen = len ;
                    start = left-step+1;
                }
            }
        }
        return s.substr(start,maxLen);
    }
};
