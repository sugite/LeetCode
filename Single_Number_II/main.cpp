class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < n; i++) {
	        twos |= ones & A[i];
	        ones ^= A[i];// ���3�� �� ��� 1�εĽ����һ����
	       //����ones �� twos �ѳ�����3�ε�λ������Ϊ0 ��ȡ��֮��1��λ��Ϊ0��
	        threes = ones & twos;
	        ones &= ~threes;
	        twos &= ~threes;
	    }
	    return ones;
    }
};

//reference :http://www.acmerblog.com/leetcode-single-number-ii-5394.html
