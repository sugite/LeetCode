/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res ;
        if(intervals.empty()){
            res.push_back(newInterval);
            return res;
        }
        int low=-1 , high=-1 ;
        for(int i = 0 ; i < intervals.size() ; i++){
            if(newInterval.start<=intervals[i].end){
                low = i ;
                break;
            }
        }
        for(int i = 0 ; i < intervals.size() ; i++){
            if(newInterval.end>=intervals[i].start){
                high = i ;
            }
        }
        if(high<0){
            res.push_back(newInterval);
            for(int i = 0 ; i < intervals.size()  ; i++){
                res.push_back(intervals[i]);
            }
            return res ;
        }
        if(low<0){
            intervals.push_back(newInterval);
            return intervals;
        }
        if(high<low){
            for(int i = 0 ; i < intervals.size()  ; i++){
                res.push_back(intervals[i]);
                if(high==i)
                   res.push_back(newInterval); 
            }
            return res ;
        }
        for(int i = 0 ; i < low ; i++){
            res.push_back(intervals[i]);
        }
        Interval temp(min(newInterval.start,intervals[low].start),max(newInterval.end,intervals[high].end));
        res.push_back(temp);
        for(int i = high+1 ; i < intervals.size() ; i++){
            res.push_back(intervals[i]);
        }
        return res ;
    }
};
