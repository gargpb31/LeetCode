class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();


        vector<vector<int>> v;
        int g = 0;
        sort(intervals.begin(),intervals.end());
        v.push_back({intervals[0][0],intervals[0][1]});

        for(int i=1 ; i<n; i++)
        {
            int y1 = v[g][0];
            int y2 = v[g][1];

            int r1 = intervals[i][0];
            int r2 = intervals[i][1];

            if(r1<=y2 && r2>y2)
            {
                v[g][1]=r2;
            }
            else if (r1<=y2 && r2<=y2) continue;
            else 
            {
                v.push_back({r1,r2});
                g++;
            }
        }
        return v;
    }
};