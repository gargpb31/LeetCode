class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        
        for(int i=1; i<n; i++)
        {
            int y = n-i;

            string k = to_string(i)+to_string(y);
            if(k.find('0')==string::npos)
            {
                return {i,y};
            }
        }
        return {};
    }
};