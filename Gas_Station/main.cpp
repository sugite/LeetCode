class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int index = 0 ; 
        int leftGas = 0 ;
        int n = gas.size();
        while( index < n ){
            int i = index ; 
            for(; i < n+index ; i++){
                leftGas += gas[i%n] - cost[i%n];
                if(leftGas<0) break;
            }
            if(i==n+index) return index ;
            index = i+1 ;
            leftGas = 0;
        }
        return -1;
    }
};
