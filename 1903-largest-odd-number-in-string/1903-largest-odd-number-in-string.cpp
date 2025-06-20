class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

        string s = num;
        for(int i=n-1; i>=0; i--)
        {
            int x = s[i]-'0';
            if(x%2==0) s.pop_back();
            else return s;
        }
        return "";
    }
};