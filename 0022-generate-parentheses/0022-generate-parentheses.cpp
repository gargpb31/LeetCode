class Solution {
public:
    void generate(int n, string s,vector<string> &v,int c,int c1){
        if(s.size()==2*n) {
            v.push_back(s);
            return;
        }

        if(c<n){
        s+='(';
        generate(n,s,v,c+1,c1);

        s.pop_back();}
        if(c1<n && c1<c){
        s+=')';
          generate(n,s,v,c,c1+1);}

    }


    vector<string> generateParenthesis(int n) {
          set<string> parenthesis;
            string s = "";
             vector<string> ans;
            generate(n,s,ans,0,0);
           

            
            return ans;


    }
};