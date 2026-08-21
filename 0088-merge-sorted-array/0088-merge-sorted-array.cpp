class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        
        while(i!=m && j!=n)
        {
            if(nums1[i]<=nums2[j])
            {
                i++;
            }
            else
            {
                swap(nums1[i],nums2[j]);
                i++;
                int r = j;
                while(j!=n-1)
                {
                    if(nums2[j]>nums2[j+1])
                    {
                        swap(nums2[j],nums2[j+1]);
                        j++;
                    }
                    else break;
                }
                j=r;

            }
            
        }
        while(j!=n)
        {
            nums1[i]=nums2[j];
            i++;
            j++;
        }
        
    }
};