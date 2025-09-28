class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        int c=0;
        while(n!=0)
        {
            int r = n%10;
            int r1 = r*pow(10,c);
            if(r1!=0)
            ans.push_back(r1);
            c++;
            n=n/10;

        }

        sort(ans.rbegin(),ans.rend());
        return ans;
        
    }

};