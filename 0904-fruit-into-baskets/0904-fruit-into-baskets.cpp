class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        multiset<int> m;
        map<int,int> m1;

        int a =0;
        int i =0;
        int ans = 0;
        while(i<n)
        {
            if(m1.find(fruits[i])==m1.end() || m1[fruits[i]]==0)
            {
                m.insert(1);
                m1[fruits[i]]++;
            }
            else
            {
                m.erase(m.find(m1[fruits[i]]));
                m1[fruits[i]]++;
                m.insert(m1[fruits[i]]);
            }

            if(m.size()<=2)
            {
                ans=max(ans,i-a+1);
                i++;
            }
            else
            {
                while(m.size()>2)
                {
                    m.erase(m.find(m1[fruits[a]]));
                    m1[fruits[a]]--;
                    if(m1[fruits[a]]!=0)
                    m.insert(m1[fruits[a]]);
                    a++;

                }
                i++;
            }
        }
        i--;
        ans=max(ans,i-a+1);
        return ans;

    }
};