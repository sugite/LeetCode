class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        vec.push_back("/");
        string dir;
        for(int i = 1 ; i < path.size() ; i++){
            if(path[i]=='/'&&dir.empty()) continue;
            else if(path[i]!='/') dir += path[i];
            else if(path[i]=='/'){
                if(dir==".."){
                    if(vec.size()>1) vec.pop_back();
                }else if(dir!="."){
                    dir += '/';
                    vec.push_back(dir);
                }
                dir.clear();
            }
        }
        if(dir.size()>0&&dir!="."&&dir!="..")
            vec.push_back(dir);
        else if(dir.size()>0&&dir=="..")
            vec.pop_back();
        dir.clear();
        for(int i = 0 ; i< vec.size();i++) dir+=vec[i];
        if(vec.empty()) return "/";
        if(dir.size()!=1&&dir[dir.size()-1]=='/')
            return dir.substr(0,dir.size()-1);
        return dir ;
    }
};
