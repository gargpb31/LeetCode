class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int left = 0;
        long int sum = 0;
        int ans = 0;
         for (int i = 0; i < n; i++) {

            sum += nums[i];
            long int s = nums[i];
            while ((i - left + 1) * (s)-sum > k) {
                sum -= nums[left];
                left++;
            }

            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};