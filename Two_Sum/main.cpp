class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> t(numbers);
        sort(numbers.begin(),numbers.end());
        int head = 0 , tail = numbers.size()-1;
        while(head<tail){
            if(numbers[head]+numbers[tail]==target)
                break;
            if(numbers[head]+numbers[tail]<target){
                head++;
                continue;
            }
            tail--;
        }
        vector<int> res ;
        for(int i = 0 ; i < t.size() ; i++){
            if(t[i]==numbers[head] || t[i]==numbers[tail]){
                res.push_back(i+1);
                break;
            }
        }
        for(int i = t.size()-1 ; i >=0 ; i--){
            if(t[i]==numbers[head] || t[i]==numbers[tail]){
                res.push_back(i+1);
                break;
            }
        }
        if(res[0]>res[1]){
            int temp = res[0];
            res[0] = res[1];
            res[1] = temp ;
        }
        return res ;
    }
};
