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
        vector<pair<int, int>>  a;
        for(auto it: intervals) {
            a.push_back({it.start, it.end});
        }
        sort(a.begin(), a.end());
        int cur = a[0].second;
        for(int i = 1; i < a.size(); ++i) {
            if(a[i].first < cur) return false;
            cur = a[i].second;
        }
        return true;
    }
};
