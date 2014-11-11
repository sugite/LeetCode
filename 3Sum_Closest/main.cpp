class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        vector<int> v(num.begin(), num.end());
        int ans = 0 ,sum;
        sort(v.begin(), v.end());
        if(v.size() <= 3) return accumulate(v.begin(), v.end(), 0);
        ans = v[0] + v[1] + v[2];
        for (int i = 0; i <v.size()-2; i++) {
            int j = i + 1;
            int k = v.size() - 1;
            while (j < k) {
                sum = v[i] + v[j] + v[k];
                if (abs(target - ans) > abs(target - sum)) {
                    ans = sum;
                    if (ans == target) return ans;
                }
                (sum > target) ? k-- : j++;
            }
        }
        return ans;
    }
};
