class Solution {
public:
    int lower(int k,vector<int> &v)
    {
        int low = 0;
        int high = v.size()-1;
        int ans = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;

            if(v[mid]>=k)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }

        }
        return ans;
    }

    long long minOperations(vector<vector<int>>& queries) {
        vector<int> v;
        v.push_back(0);
        v.push_back(3);
        int x = 3;
        int i =2;
        while(x<1e9)
        {
                int y = pow(4,i);
                  
                  if((y-1)<=1e9)
                v.push_back(y-1);
                else break;
              
                i++;
        }
     
        v.push_back(1e9);
        for(auto it : v ) cout<<it<<endl;
         long long ans = 0;
        for(auto it : queries)
        {
            int start = it[0];
            int end = it[1];
            long long o1 = 0;
            int e1 = 0;
            int r = 1;
            while(e1<end)
            {
                long long  di = min(v[r],end)-e1;
                o1+=(di*r);
                e1=min(v[r],end);
                r++;


            }
            if(start==1)
            {
                ans+=((o1+1)/2);
            }
            else
            {
                long long o2=0;
                int e2 = 0;
                int r2 =1;
                start=start-1;
                while(e2<start)
                {
                    long long di = min(v[r2],start)-e2;
                    o2+=(di*r2);
                    e2=min(v[r2],start);
                    r2++;
                }
                ans+=((o1-o2+1)/2);
            }


            

        }


        return ans;
        
    }
};