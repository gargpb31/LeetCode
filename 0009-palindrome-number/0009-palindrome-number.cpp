class Solution {
public:
    bool isPalindrome(int x) {
       
        if(x<0) return false;
        int s = x;
        long long rev = 0;
        while(s!=0)
        {
            rev=rev*10+s%10;
            s/=10;

        }
        
        if(x==rev) return true;
        return false;

    }
};