class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();

        if(n!=m) return false;

        for(int i=0; i<n; i++)
        {
            if(s==goal) return true;
            char c = s[0];
            reverse(s.begin(),s.end());
            s.pop_back();
            reverse(s.begin(),s.end());
            s+=c;

        }
        return false;
    }
};