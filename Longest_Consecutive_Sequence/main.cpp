class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        map<int,int> m;
        size_t size = num.size() ;
        int ret = 0;
        int lhs = 0 , rhs = 0 , consecutive = 0 ;
        for(int i = 0 ; i < size ; ++i){
            if(m.count(num.at(i))==0){
                lhs = m.count(num.at(i)-1)>0 ? m[num.at(i)-1] : 0;
                rhs = m.count(num.at(i)+1)>0 ? m[num.at(i)+1] : 0;
                consecutive = lhs + rhs + 1 ;
                m[num.at(i)] = consecutive;
                m[num.at(i)-lhs] = consecutive;
                m[num.at(i)+rhs] = consecutive;
                if(consecutive > ret) ret = consecutive;
            }
        }
        return ret ;
    }
};