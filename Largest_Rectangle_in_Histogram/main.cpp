class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int max = 0 ; 
        height.push_back(0);
        vector<int> stack;
        for(int i = 0 ; i < height.size() ; ){
            if(stack.empty() || height[stack.back()] <= height[i]){
                stack.push_back(i++);
            }else{
                int index = stack.back();
                stack.pop_back();
                int len = stack.empty() ? i : i - stack.back() - 1  ;
                if(len*height[index]>max) max = len*height[index];
            }
        }
        return max ;
    }
};
