class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0 || x<10) return true;

       long int rev = 0;
       long int num = x;
       while(x!=0)
       {
        int rem = x%10;
        rev = rev*10+rem;
        x=x/10;
       }
       if(num==rev) return true;
       return false; 
       

    }
};