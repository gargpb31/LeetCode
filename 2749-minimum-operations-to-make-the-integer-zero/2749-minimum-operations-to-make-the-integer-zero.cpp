class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num2>num1) return -1;
        
        int k = 1; // base case start with 1;
        while(true)
        {
            long long s = num2;
           long long x = num1-k*s;
            if(x<k)
            {
                return -1; //then obv 2^i can't be negative
            }
            else
            {
                long long y = __builtin_popcountll(x);
                if(k>=y) return k;
            }
            k++;
        }

    }
};