class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = friends.size();
        map<int,int> m;
        for(int i=0; i<n; i++)
        {
            m[friends[i]]++;
        }

        int m1 =order.size();
        vector<int> ans;
        for(int i=0; i<m1; i++)
        {
            if(m.find(order[i])!=m.end()) ans.push_back(order[i]);
        }
        return ans;
    }
};