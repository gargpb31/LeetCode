class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.rbegin(),s.rend());
        sort(g.rbegin(),g.rend());

        int n = s.size();
        int m = g.size();

        int count = 0;

        int a = 0;
        int b = 0;

        while(a<m && b<n)
        {
            if(s[b]>=g[a])
            {
                count++;
                a++;
                b++;
            }
            else
            {
                a++;
            }
        }

        return count;

    }
};