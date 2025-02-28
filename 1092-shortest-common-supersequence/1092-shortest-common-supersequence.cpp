class Solution {
public:
    void func(vector<vector<int>>& dp, int n, int m, int l, string& s,
              string s1, string s2) {

        if (s.size() == l)
            return;
        if (n == 0 || m == 0)
            return;

        if (s1[n - 1] == s2[m - 1]) {
            s += s1[n - 1];
            func(dp, n - 1, m - 1, l, s, s1, s2);

        } else {
            if (dp[n - 1][m] > dp[n][m - 1]) {
                func(dp, n - 1, m, l, s, s1, s2);
            } else
                func(dp, n, m - 1, l, s, s1, s2);
        }
    }

    string shortestCommonSupersequence(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string s = "";
        int l = dp[n][m];
        func(dp, n, m, l, s, s1, s2);
        reverse(s.begin(), s.end());

        int g = 0;
        int g1 = 0;
        int g2 = 0;
        string ans = "";

        while (g1 < n && g2 < m && g < s.size()) {

            if (s1[g1] == s[g] || s2[g2] == s[g]) {
                if (s1[g1] == s2[g2]) {
                    ans += s1[g1];
                    g1++;
                    g2++;
                    g++;
                } else if (s1[g1] == s[g]) {
                    while (s2[g2] != s[g]) {
                        ans += s2[g2];
                        g2++;
                    }
                    ans += s2[g2];
                    g1++;
                    g2++;
                    g++;
                } else {
                    while (s1[g1] != s[g]) {
                        ans += s1[g1];
                        g1++;
                    }
                    ans += s2[g2];
                    g1++;
                    g2++;
                    g++;
                }
            } else {
                ans += s1[g1];
                ans += s2[g2];
                g1++;
                g2++;
            }
        }
        while (g1 < n) {
            ans += s1[g1];
            g1++;
        }

        while (g2 < m) {
            ans += s2[g2];
            g2++;
        }

        return ans;
    }
};