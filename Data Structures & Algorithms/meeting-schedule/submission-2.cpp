/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() <= 1) return true;
        // 1. sort
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            return a.start < b.start;
        });
        // 2. compare w/ neighbor
        for(int i = 0; i < intervals.size()-1; i++){
            if(intervals[i].start < intervals[i+1].end && intervals[i].end > intervals[i+1].start){
                return false;
            }
        }
        return true;
    }
};
