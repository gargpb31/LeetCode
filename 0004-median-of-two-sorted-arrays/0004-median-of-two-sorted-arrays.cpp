class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); 
        int n2 = nums2.size();

        if(n>n2) return findMedianSortedArrays(nums2,nums1);

        int low = 0;
        int high = n;

        while(low<=high)
        {
            int cut1 = (low+high)/2;
            int cut2 = (n+n2+1)/2-cut1;

            int left1 = INT_MIN;
            if(cut1!=0) left1=nums1[cut1-1];
            int left2 = INT_MIN;
            if(cut2!=0) left2=nums2[cut2-1];

            int right1 = INT_MAX;
            if(cut1!=n) right1=nums1[cut1];
            int right2 = INT_MAX;
            if(cut2!=n2) right2 = nums2[cut2];

            if(left1<=right2 && left2<=right1)
            {
                if((n+n2)%2==0)
                {
                    return (max(left1,left2)+min(right1,right2))/2.0;

                }
                else
                {
                    return max(left1,left2);
                }
            }
            else if(left1>right2)
            {
                high=cut1-1;
            }
            else
            {
                low=cut1+1;
            }


        }
        return -1;
    }
};