class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candy(ratings.size(),1);
        for(int i = 1 ; i < ratings.size() ; ++i){
            if(ratings.at(i)>ratings.at(i-1))
                candy.at(i) = candy.at(i-1) + 1;
        }
        
        for(int i = ratings.size() - 1 ; i > 0 ; --i){
            if(ratings.at(i-1) > ratings.at(i))
                candy.at(i-1) = max(candy.at(i-1) , candy.at(i)+1);
        }
        
        return accumulate(candy.begin(),candy.end(),0) ;
    }
};