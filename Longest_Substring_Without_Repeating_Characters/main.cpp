class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> set ;
        int ret =0 ; 
        for(int i = 0 ,j = 0 ; j < s.size() ; ++j){
            if(set.find(s[j])==set.end()){
                set.insert(s[j]);
                if(set.size()>ret)
                    ret = set.size();
                continue;
            }
            while(set.find(s[j])!=set.end()&&!set.empty()){
                set.erase(s[i++]);
            }
            set.insert(s[j]);
        }
        return ret;
    }
};
