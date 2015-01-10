class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > ret ;
        vector<list<string> > r = partition1(s);
        for(int i = 0 ; i < r.size() ; ++i){
            vector<string> tmp ;
            while(!r[i].empty()){
                tmp.push_back(r[i].front());
                r[i].pop_front();
            }
            ret.push_back(tmp);
        }
        return ret ;
    }
    
    vector<list<string> > partition1(string s) {
        vector<list<string> > ret ;
        if(s=="") return ret ;
        for(int i =  1 ; i < s.size() ; ++i){
            string str = s.substr(0,i);
            string str1 = s.substr(i);
            if(palindrome(str)){
                vector<list<string> > tmp = partition1(str1);
                for(int j = 0 ; j < tmp.size() ; ++j){
                    tmp[j].push_front(str);
                    ret.push_back(tmp[j]);
                }
            }
        }
        if(palindrome(s)){
            ret.push_back(list<string>(1,s));
        }
        return ret ;
    }
    
    bool palindrome(const string& s)
    {
        int i = 0 , j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            ++i,--j;
        }
        return true;
    }
};