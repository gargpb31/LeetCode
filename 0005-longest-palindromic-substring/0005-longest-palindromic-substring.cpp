class Solution {
public:
    string longestPalindrome(string s) {
      //  Approach : O(n^2) solution
      // iterate through each character of string as palindrome;
        int ans=1;
        string anss="";
        anss+=s[0];
      for(int i=0; i<s.size()-1; i++){
        
        if(s[i]==s[i+1]){
            
            int g=i;
            int g1=i+1;
            string k1="";
            
            while(g>=0 && g1<s.size()){
                if(s[g]==s[g1]) {
                    k1+=s[g1];
                    g--;
                    g1++;
                }
                else break;
            }
      
            reverse(k1.begin(),k1.end());
            string k2 = k1;
            reverse(k1.begin(),k1.end());
            k2+=k1;
            if(k2.size()>ans){
                ans=k2.size();
                anss=k2;
            }
            


        }
        
            int g=i-1;
            int g1=i+1;
            string k1="";
            
            while(g>=0 && g1<s.size()){
                if(s[g]==s[g1]) {
                    k1+=s[g1];
                    g--;
                    g1++;
                }
                else break;
            }
            if(i==1) cout<<k1;
            reverse(k1.begin(),k1.end());
            string k2 = k1;
            k2+=s[i];
             reverse(k1.begin(),k1.end());
            k2+=k1;
             if(k2.size()>ans){
                ans=k2.size();
              
                anss=k2;
            }


        
      }
      return anss;


    }
};