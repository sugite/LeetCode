class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0 , last = 0 , i = 0;
        while(*(s+i)!='\0'){
            if(*(s+i++)==' ') last = len>0? len : last , len = 0;
            else len++;
        }
        return len>0?len:last ;
    }
};
