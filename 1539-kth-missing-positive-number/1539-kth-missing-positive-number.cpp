class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low=0;
        int high = n-1;
        int d = arr[low]-1;
        if(n==1)
        {
            int ans = k;
            if(arr[0]<=k) ans++;
            return ans;
        }
        if(n==2)
        {
            int ans = k;
            if(arr[0]<=k) ans++;
            if(arr[1]<=ans) ans++;
            return ans;
        }
        if(k<=d) return k;
        else k-=d;
        
        while(low+1<high)
        {
            int mid = (low+high)/2;
            int x = arr[mid]-arr[low];
            int x1 = mid-low;
            if((x-x1)>=k) 
            {
                high=mid;
            }
            else
            {
                k-=(x-x1);
                low=mid;
            }
            
        }
        int ans = arr[low]+k;
        if(ans>=arr[high]) ans++;
        return ans;
    }
};