class Solution {
public:
    int reverse(int x) {
       int flag = 0;
       if(x<0) flag++;
    
       long int xx = x;
       xx=abs(xx);
       long long int g = pow(2,31);
       g-=1;
       long long int g1 = pow(2,31);
       long int rev = 0;
       while(xx!=0)
       {
            int r = xx%10;
            xx=xx/10;
            rev=rev*10+r;
            if(rev>g)
            {
                return 0;
            }
            if(flag>0)
            {
                if(rev>g1) return 0;
            }

       }
       int ans = rev;
       if(flag>0) return -ans;
       return ans;
        
    }
};