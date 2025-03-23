class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> graph(n);
        for (auto it : roads) {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }
        long long mod = 1e9 + 7;
        vector<long long> ways(n, 0);
        set<pair<long long, int>> s;
        vector<long long> ans(n, LLONG_MAX);
        ans[0] = 0;
        ways[0] = 1;
        s.insert({0, 0});
        while (!s.empty()) {
            auto it = s.begin();
            long long x = (*it).first;
            int y = (*it).second;
            s.erase(it);

            for (auto it : graph[y]) {
                long long nv = it.second + x;

                if (ans[it.first] > nv) {
                    ans[it.first] = nv;
                    ways[it.first] = ways[y];
                    s.insert({nv, it.first});

                } else if (ans[it.first] == nv) {
                    ways[it.first] += ways[y];
                    ways[it.first] %= mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
