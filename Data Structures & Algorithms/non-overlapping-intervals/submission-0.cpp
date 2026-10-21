class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;

        sort(intervals.begin(),intervals.end(),
            [](const vector<int>& a,const vector<int>& b){
                return a[1] < b[1];
            }
        );
        int endtime = intervals[0][1];
        int removed = 0;

        for(int i=1;i<intervals.size();i++){
            if(endtime <= intervals[i][0]){
                endtime = intervals[i][1];
            } else {
                removed++;
            }
        }
        return removed;
    }
};
