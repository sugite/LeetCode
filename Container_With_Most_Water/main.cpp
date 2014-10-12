class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0, right = height.size()-1 ,maxA = 0;  
        while(left < right)  
        {  
            maxA = max(maxA,(right-left)*min(height[left],height[right]));
            if(height[left]<height[right])left++;  
            else right--;  
        }  
        return maxA;  
    }
};
