class Solution {
public:
    int majorityElement(vector<int> &num) {
        int ret , times = 0;
        for(int i = 0 ; i < num.size() ; i++){
            if(times==0){
                ret = num[i];
                times++;
            }else{
                if(ret == num[i]) times++;
                else times--;
            }
        }
        return ret ;
    }
};