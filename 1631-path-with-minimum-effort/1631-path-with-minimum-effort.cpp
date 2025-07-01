class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> ans(row,vector<int>(col,1e6));

        ans[row-1][col-1]=0;

       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

       pq.push({0,{row-1,col-1}});
       while(!pq.empty())
       {
        auto p = pq.top();
        pq.pop();

        if(ans[p.second.first][p.second.second]<(p.first)) continue;

        int ro[] = {-1,0,+1,0};
        int co[] = {0,+1,0,-1};

        for(int i=0; i<4; i++)
        {
            int nr = p.second.first+ro[i];
            int nc = p.second.second+co[i];

            if(nr>=0 && nc>=0 && nr<row && nc<col)
            {
int cal = abs(heights[p.second.first][p.second.second]-heights[nr][nc]);
        cal=max(cal,ans[p.second.first][p.second.second]);

            if(ans[nr][nc]>cal) {

                ans[nr][nc]=cal;
                pq.push({cal,{nr,nc}});
            }
            }
        }
       }

        return ans[0][0];



    }
};