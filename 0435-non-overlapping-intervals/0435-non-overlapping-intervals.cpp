class Solution {
public:
    static bool cmn(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.second==b.second)
        {
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<pair<int,int>> v;

        for(int i=0; i<n; i++)
        {
            v.push_back({intervals[i][0],intervals[i][1]});
        }

        int endtime = -50000;
        int ans = 0;

        sort(v.begin(),v.end(),cmn);
       
        for(int i=0; i<n; i++)
        {
            if(v[i].first>=endtime)
            {
                endtime=v[i].second;
               
            }
            else ans++;
        }
        return ans;
    }
};