#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    	void reverseWords(string &s) {
	    	s+=' ';
		string temp(s);
		s.clear();
		string word;
		for(string::iterator it = temp.begin(); it != temp.end() ; ++ it)
		{
			if(*it == ' '){
				if(word.size()){
					word = ' ' + word;
					s = word + s ;
				}
				word.clear();
			}
			else
				word+=(*it);
		}
		s.erase(0,1);
	}
};

int main(void)
{
	Solution sol;
	string s("a");
	sol.reverseWords(s);
	cout<<s<<"1"<<endl;
	return 0;	
}
