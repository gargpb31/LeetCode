class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> v(n,1);


        int ans = n;
        int i=1;
        while(i<n)
        {
             int peak = 0;
            int valley = 0;
            if(ratings[i]==ratings[i-1]) i++;
            while(i<n && ratings[i]>ratings[i-1])
            {
                
                peak++;
                ans+=(peak);
                i++;
            }
            while(i<n && ratings[i]<ratings[i-1])
            {
                valley++;
                ans+=(valley);
                i++;
            }
            
            ans-=(min(peak,valley));

            
        }
        return ans;
    }
};