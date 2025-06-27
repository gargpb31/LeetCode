class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> v;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        if(n==1) return intervals;
        int a = intervals[0][0];
        int b = intervals[0][1];

        for(int i=1; i<n; i++)
        {
            if(intervals[i][0]>b)
            {
                v.push_back({a,b});
                a=intervals[i][0];
                b=intervals[i][1];
            }
            else
            {
                b=max(intervals[i][1],b);
            }
        }
        v.push_back({a,b});
        return v;
    }
};