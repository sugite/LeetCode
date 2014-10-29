class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()<2) return true;
        int head = 0 , tail = s.size()-1;
        while(head<tail){
            if(!isCH(s[head])){
                head++;
                continue;
            }
            if(!isCH(s[tail])){
                tail--;
                continue;
            }
            if(upper(s[head])==upper(s[tail])){
                head++;
                tail--;
                continue;
            }
            return false;
        }
        return true;
    }
    char upper(char c){
        if(c>='a'&&c<='z') return c+'A'-'a';
        return c;
    }
    bool isCH(char c){
        return (c>='a'&&c<='z') || (c>='A'&&c<='Z') || (c>='0'&&c<='9') ;
    }
};
