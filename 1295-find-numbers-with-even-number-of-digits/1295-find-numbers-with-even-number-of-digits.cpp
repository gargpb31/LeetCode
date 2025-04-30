class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();

        int count = 0;

        for(int i=0; i<n; i++)
        {
            int x = nums[i];
            int dig = 0;
            while(x!=0)
            {
                x=x/10;
                dig++;
            }
            if(!(dig & 1)) count++;
        }

        return count;
    }
};