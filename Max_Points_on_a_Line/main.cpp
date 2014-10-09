#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Point{
public:
	int x;
	int y;
	Point():x(0),y(0){}
	Point(int a,int b):x(a),y(b){}
};

class Solution{
public:
	int maxPoints(vector<Point> &points){
		if(points.size()<=2)
			return points.size();
		int res = 0 ;
		for(int i = 0 ; i < points.size() ; ++i){
			map<pair<int,int>,int> lines ;
			int generalmax = 0, overlap = 0 , vertical = 0;
			for(int j = i+1 ; j < points.size() ; ++j){
				int a = points[i].x - points[j].x;
				int b = points[i].y - points[j].y;
				if(a==0 && b==0){
					overlap++;
					continue;
				}else if(a==0){
					vertical++;
				}else{
					int factor = gcd(a,b);
					a/=factor;
					b/=factor;
					lines[make_pair(a,b)]++;
					generalmax = max(generalmax,lines[make_pair(a,b)]);
				}
				generalmax = max(generalmax,vertical);
				
			}
			res = max(res,generalmax+overlap+1);
		}
		return res;
	}

	int gcd(int a,int b){
		if(b==0) return a;
		return gcd(b,a%b);
	}
};

int main(void)
{
	Solution sol;
	vector<Point> points;
	points.push_back(Point(3,4));
	points.push_back(Point(6,8));
	points.push_back(Point(9,12));
	points.push_back(Point(0,0));
	cout<<sol.maxPoints(points)<<endl;
	return 0;
}
