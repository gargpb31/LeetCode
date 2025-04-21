class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int n = arr.size();

        if(n==1)
        {
            int ans = k;
            if(ans>=arr[0]) ans++;
            return ans;
        }
        if(n==2)
        {
            int ans = k;
            if(ans>=arr[0]) ans++;
            if(ans>=arr[1]) ans++;
            return ans;
        }
        if(arr[0]!=1 && k==1) return 1;
        if(arr[0]!=1){
        reverse(arr.begin(),arr.end());
        arr.push_back(1);
         reverse(arr.begin(),arr.end());
         k--;
        }
        
        int low = 0;
        int high = arr.size()-1;

        while(high-low>1)
        {
            int mid = low+(high-low)/2;
        
            int diff = arr[mid]-arr[low]+1;
            
            
            
            int diff2 = mid-low+1;
        
            int dif = diff-diff2;
           
            if(dif>=k)
            {
                high = mid;
            }
            else
            {
                k-=dif;
                low=mid;
            }
        }
       
        int ans = arr[low]+k;

        if(ans>=arr[high]) ans++;
        return ans;

    }
};