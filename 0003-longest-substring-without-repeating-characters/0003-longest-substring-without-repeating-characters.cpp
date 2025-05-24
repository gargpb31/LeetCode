class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int a = 0;
        int b = 0;

        int n = s.size();

        map<char,int> m;

        while(b<n)
        {
            if(m[s[b]]!=1){
                m[s[b]]++;
                b++;
            }
            else
            {
                ans=max(ans,b-a);
                m[s[a]]--;
                a++;
            }
        }
        ans=max(ans,b-a);
        return ans;
    }
};