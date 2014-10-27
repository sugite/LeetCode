/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool operator<(const Interval &a, const Interval &b){return a.start < b.start ;}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res ;
        if(intervals.size()==0) return res;
        sort(intervals.begin(),intervals.end());
        int low = intervals[0].start;
        int high = intervals[0].end;
        for(int i = 1 ; i<intervals.size() ; ++i){
            if(intervals[i].start<=high)
                high = max(high,intervals[i].end);
            else{
                res.push_back(Interval(low,high));
                low = intervals[i].start ;
                high = intervals[i].end ;
            }
        }
        res.push_back(Interval(low,high));
        return res ;
    }
};
