class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int g = n-1;
        int g1 = m-1;
        int g2 = m+n-1;
        while(g>=0 && g1>=0)
        {
            if(nums1[g1]>nums2[g])
            {
                swap(nums1[g1],nums1[g2]);
                g2--;
                g1--;
            }
            else
            {
                swap(nums1[g2],nums2[g]);
                g--;
                g2--;
            }
        }
        while(g>=0)
        {
            swap(nums1[g2],nums2[g]);
            g--;
            g2--;
        }


        
    }
};