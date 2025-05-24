class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        int g = 0;
        for(auto it : words)
        {
            for(auto it1 : it)
            {
                if(it1==x) 
                {
                    ans.push_back(g);
                    break;
                }
            }
            g++;
        }

        return ans;
    }
};