class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.size()<2 || num[0]<num[num.size()-1]) return num[0];
        int low = 0 ; 
        int high = num.size()-1 ;
        while(low<high-1){
            int mid = (low+high)/2;
            if(num[low]==num[mid] && num[mid]==num[high]){
                low++;
                high--;
            }else if(num[low]<=num[mid] && num[mid]<=num[high]){
                return num[low];
            }else{
                if(num[low]<=num[mid])
                    low = mid ;
                else
                    high = mid ;    
            }
        }
        return min(num[low],num[high]);
    }
};
