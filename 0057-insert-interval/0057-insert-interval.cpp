class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        int n = interval.size();

        vector<vector<int>> v;

        int x = newInterval[0];
        int y = newInterval[1];
        int temp = 0;

        interval.push_back({x,y});
        sort(interval.begin(),interval.end());

        v.push_back({interval[0][0],interval[0][1]});
        int g = 0;
        for(int i = 1; i<=n; i++)
        {
            int r1 = v[g][0];
            int r2 = v[g][1];

            int y1 = interval[i][0];
            int y2 = interval[i][1];

            if(y1>=r1 && y2<=r2) continue;
            else if (y1<=r2 && y2>r2) 
            {
                v[g][1]=y2;
                

            }
            else 
            {
                v.push_back({y1,y2});
                g++;
            }
        }
        return v;
    }
};