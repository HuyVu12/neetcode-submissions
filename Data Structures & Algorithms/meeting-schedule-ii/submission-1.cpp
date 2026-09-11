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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        vector<int> d(1000001, 0);
        for(auto it: intervals) {
            d[it.start] += 1;
            d[it.end] -= 1;
        }
        int ans = 1;
        for(int i = 1; i < 1000000; ++i) {
            d[i] += d[i-1];
            ans = max(ans, d[i]);
        }
        return ans;
    }
};
