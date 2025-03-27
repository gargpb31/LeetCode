class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < flights.size(); i++) {
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        vector<int> ans(n,1e9);
       ans[src]=0;
        set<pair<int, pair<int, int>>> s;
        s.insert({0, {src, 0}});

        while (!s.empty()) {
            auto it = s.begin();
            int x = (*it).first;
            int y = (*it).second.first;
            int z = (*it).second.second;

            s.erase(it);

            for (auto it2 : graph[y]) {
                int nn = z + it2.second;
            
                    if (x <= k) {
                        if (ans[it2.first] > nn) {
                            ans[it2.first] = nn;
                            s.insert({x+1, {it2.first, nn}});
                        }
                    }
                
            }
        }
        
        if (ans[dst] == 1e9)
            return -1;
        return ans[dst];
    }
};