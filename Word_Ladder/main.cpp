class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int len = start.size();
        int max = dict.size();
        list< string > q ;
        q.push_back(start+to_string(0));
        unordered_set<string> keng ;
        keng.insert(start);
        string tmp;
        while(!q.empty()){
            tmp = q.front();
            string nimei = tmp.substr(0,len) ;
            q.pop_front();
            int step = stoi(tmp.substr(len));
            if(transform(end,nimei)) return step+2;
            if(step+3>max) break;
            
            for(int i = 0 ; i < nimei.size() ; ++i){
                char hehe = nimei[i];
                for(char ch = 'a' ; ch <= 'z' ; ++ch){
                    if(hehe==ch) continue;
                    nimei[i] = ch ;
                    if(dict.count(nimei)>0&&keng.count(nimei)==0){
                        q.push_back(nimei + to_string(step+1));
                        keng.insert(nimei);
                    }
                }
                nimei[i] = hehe;
            }
            
            
            // for(int i = 0 ; i < d.size() ; ++i){
            //     if(keng.count(d[i])>0) continue;
            //     if(transform(tmp.substr(0,len),d[i])){
            //         q.push_back(d[i] + to_string(step+1));
            //         keng.insert(d[i]);
            //         //if(transform(end,s)) return step+3;
            //     }
            // }
        }
        return 0;
    }
    
    bool transform(const string& a, const string& b)
    {
        int count = 0;
        for(int i = 0 ; i < a.size() ; ++i){
            if(a[i]!=b[i]) ++count;
        }
        return count == 1;
    }
};