/* Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6. 
 */
#include<iostream>
using namespace std;

/*template<typename T>
T max(T a, T b)
{
	return a>b?a:b;
}

template<typename T>
T min(T a, T b)
{
	return a<b?a:b;
}
*/

class Solution{
public:
	int maxProduct(int A[], int n){
		int *maxA = new int[n];
		int *minA = new int[n];
		maxA[0] = minA[0] = A[0];
		int value = A[0];
		for(int i = 1 ; i != n ; ++i){
			maxA[i] = max( A[i] , max( A[i]*maxA[i-1] , A[i]*minA[i-1] ) );
			minA[i] = min( A[i] , min( A[i]*maxA[i-1] , A[i]*minA[i-1] ) );
			value = max( value , maxA[i] );
		}
		delete[] maxA;
		delete[] minA;
		return value;
	}
};

int main(void)
{
	int A[] = {2,3,-2,4,1,-3,-4,-5,0};
	Solution sol;
	cout<<sol.maxProduct(A,9)<<endl;
	return 0;
}




