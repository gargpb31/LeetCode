class Solution {
public:
    int ans = 0;
    void mergesort(vector<int> &nums,int a,int mid,int b)
    {
        vector<int> leftarray(mid-a+1);
        vector<int> rightarray(b-mid);
        int size2 = b-mid;
        int size1 = mid-a+1;

        for(int i=a; i<=mid; i++)
        {
            leftarray[i-a]=nums[i];
        }
        for(int i=mid+1; i<=b; i++)
        {
            rightarray[i-(mid+1)]=nums[i];
        }

        vector<int> fina;

        int leftpointer = 0;
        int rightpointer = 0;

        while(leftpointer<size1)
        {
                int value = (leftarray[leftpointer]-1)/2;

                while(rightpointer<size2 && rightarray[rightpointer]<=value)
                {
                    rightpointer++;
                }
                ans+=(rightpointer);
                leftpointer++;
        }
        leftpointer = 0;
        rightpointer = 0;
        while(leftpointer<size1 && rightpointer<size2)
        {
            if(leftarray[leftpointer]<rightarray[rightpointer])
            {
                fina.push_back(leftarray[leftpointer]);
                leftpointer++;
            }
            else
            {
                fina.push_back(rightarray[rightpointer]);
                rightpointer++;
            }
        }
        while(leftpointer<size1)
        {
fina.push_back(leftarray[leftpointer]);
                leftpointer++;
        }
        while(rightpointer<size2)
        {
               fina.push_back(rightarray[rightpointer]);
                rightpointer++;
        }

        for(int i=a; i<=b; i++)
        {
            nums[i]=fina[i-a];
        }
        

    }

    void merge(vector<int> &nums,int a,int b)

    {
        if(a<b)
        {
            int mid = (a+b)/2;
            merge(nums,a,mid);
            merge(nums,mid+1,b);
            mergesort(nums,a,mid,b);
        }
    }

    int reversePairs(vector<int>& nums) {
        int n  = nums.size();
        if(n==1) return 0;
        merge(nums,0,n-1);
        return ans;
    }
};