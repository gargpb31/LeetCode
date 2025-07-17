class Solution {
public:

    void generate(vector<int> arr,vector<int> &nums,int i,vector<vector<int>> &fin)
    {
        if(i==nums.size())
        {
            fin.push_back(arr);
            return;
        }

        
        generate(arr,nums,i+1,fin);
        arr.push_back(nums[i]);
        generate(arr,nums,i+1,fin);

    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        generate(arr,nums,0,ans);
        return ans;
    }
};