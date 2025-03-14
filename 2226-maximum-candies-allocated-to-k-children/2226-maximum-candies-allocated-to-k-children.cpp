class Solution {
public:
    bool func(vector<int> &candies, long long k,long long mid){
       long long count=0;
        for(auto it : candies){
            count+=(it/mid);
        }
        if(count>=k) return true;
        return false;
    }


    int maximumCandies(vector<int>& candies, long long k) {
        long long low=1;
        long long high=1e12;
        while(low<=high){
            long long mid = (low+high)/2;
            if(func(candies,k,mid)){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return high;
    }
    
};