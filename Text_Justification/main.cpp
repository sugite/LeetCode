class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        if(L==0) return words;
        vector<string> res ;
        string tmp ; 
        for(int i = 0 ; i < words.size() ; i++){
            if(tmp.empty()){
                tmp += words[i];
            }else{
                if(tmp.size()+1+words[i].size()<=L){
                    tmp = tmp + " " + words[i];
                }else{
                    res.push_back(tmp);
                    tmp = words[i];
                }
            }
        }
        res.push_back(tmp);
        for(int i = 0 ; i < res.size() ; i++){
            if(i>0&&i==res.size()-1){
                res[i]+=string(L - res[i].size(),' ');
                continue;
            }
            tmp = res[i] ;
            int num = 0 ;
            for(int j = 0 ; j < tmp.size() ; j++)
                if(tmp[j]==' ') num++;
            int left = L - tmp.size() ; 
            if(num==0){
                tmp = tmp + string(left,' ');
            }else{
                int divv = left/num;
                int qian = left%num;
                tmp.clear();
                for(int k = 0 ; k < res[i].size() ; k++){
                    tmp += res[i][k] ;
                    if(res[i][k]==' '){
                        tmp += string(divv,' ');
                        if(qian-->0) tmp+=' ';
                    }
                }
            }
            res[i] = tmp ;
        }
        return res ;
    }
};
