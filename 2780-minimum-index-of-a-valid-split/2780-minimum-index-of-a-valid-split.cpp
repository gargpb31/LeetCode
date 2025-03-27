class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        for(auto it : nums){
            m[it]++;
        }
        int x = -1;
        int y = 0;
        for(auto it : m){
            if(it.second>y){
                y=it.second;
                x=it.first;
            }
        }
       

        map<int,int> m2;
        int c=0;
        int g=0;
        for(auto it : nums){
            if(it==x) c++;
            if(c>((g+1)/2)) {
                int c1=m[x]-c;
                if(c1>((n-g-1)/2)) return g;
            }
            g++;
            
        }
        return -1;
    }
};