class Solution {
public:
    bool func(vector<int>& ranks, int cars,long long mid){
        long long count=0;
        for(int i=0; i<ranks.size(); i++){
            long long r = ranks[i];
            long long x = mid/(r);
            long long y = sqrtl(x);
            count+=y;
        }
        long long c = cars;
        if(count>=c) return true;
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
      long long high = 1e18;
        long long low = 1;
        while(low<=high){
            long long mid = (low+high)/2;
            if(func(ranks,cars,mid)){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};