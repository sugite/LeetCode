#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

class Solution{
public:
	int evalRPN(vector<string> &tokens){
		vector<string> operand;
		for(vector<string>::iterator it = tokens.begin() ; it != tokens.end() ; ++it){
			string temp = *it;
			if((temp[0]<='9'&&temp[0]>='0') || temp.size()>1)
				operand.push_back(temp);
			else{
				int a,b,c ;
				b = strToInt(operand.back());
				operand.pop_back();
				a = strToInt(operand.back());
				operand.pop_back();
				switch(temp[0]){
					case '+': c = a+b ;break;
					case '-': c = a-b ;break;
					case '*': c = a*b ;break;
					case '/': c = a/b ;break;
				}
				operand.push_back(intToStr(c));
			}
		}
		return strToInt(operand.back());
	}
	
	int strToInt(const string &str){
		int flag = str[0]=='-' ? -1 : 1 ;
		int res;
		stringstream ss ;
		ss<<(flag>0?str:str.substr(1));
		ss>>res ;
		ss.clear();
		return flag*res ;
	}
	
	string intToStr(const int &num){
		string res;
		int temp = num < 0 ? -num : num;
		stringstream ss ;
		ss<<temp ;
		ss>>res ;
		ss.clear();
		res = (num < 0 ? "-" : "") + res;
		return res ;
	}
};


int main(void)
{
	vector<string> tokens;
	tokens.push_back("3");
	tokens.push_back("-4");
	tokens.push_back("+");
	Solution sol;
	cout<<sol.evalRPN(tokens)<<endl;
	return 0;
}
