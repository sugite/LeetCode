#include<iostream>
#include<vector>
using namespace std ;


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(target<matrix[0][0] || target>matrix[matrix.size()-1][matrix[0].size()-1])
            return false;
        vector<int> col(matrix.size(),0);
        for(int i = 0 ; i < col.size() ; ++i){
            col[i] = matrix[i][0];
        }
        int index = binarySearch(col,target);
        if(index == -1){
            index = matrix.size();
        }else if(col[index]==target) return true;
        int index1 = binarySearch(matrix[index-1],target);
        if(matrix[index-1][index1]==target) return true;
        return false;
    }
    
    int binarySearch(vector<int> &a , int key){
        if(key<a[0]) return 0;
        if(key>a[a.size()-1]) return -1;
        int low = 0;
        int high = a.size()-1;
        while(low<high){
        	int mid = (low+high)/2;
            if(a[mid]>=key){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};

int main()
{
	vector< vector<int> > m(3,vector<int>(4,0));
	m[0][0] = 1;
	m[0][1] = 3;
	m[0][2] = 5;
	m[0][3] = 7;
	m[1][0] = 10;
	m[1][1] = 11;
	m[1][2] = 16;
	m[1][3] = 20;
	m[2][0] = 23;
	m[2][1] = 30;
	m[2][2] = 34;
	m[2][3] = 50;
	Solution sol;
	cout<<sol.searchMatrix(m,13)<<endl;
	return 0;
}
