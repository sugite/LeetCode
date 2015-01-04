class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        return func(num,0,num.size()-1);
    }
    
private:
    int func(const vector<int> &num, int left ,int right){
        if(left==right) return left ;
        if(left+1==right) return num.at(left)>num.at(right)?left:right;
        int mid = ( left + right ) / 2;
        if(num.at(mid-1)<num.at(mid) && num.at(mid)>num.at(mid+1)) return mid;
        if(num.at(mid-1)<num.at(mid) && num.at(mid)<num.at(mid+1)) return func(num,mid+1,right);
        return func(num,left,mid-1);
    }
};