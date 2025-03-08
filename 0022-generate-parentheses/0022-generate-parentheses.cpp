class Solution {
public:
    void generate(int n, string s,set<string> &v,int c,int c1){
        if(s.size()==2*n) {
            v.insert(s);
            return;
        }

        if(c<n){
        s+='(';
        generate(n,s,v,c+1,c1);

        s.pop_back();}
        if(c1<n){
        s+=')';
          generate(n,s,v,c,c1+1);}

    }


    vector<string> generateParenthesis(int n) {
          set<string> parenthesis;
            string s = "";
            generate(n,s,parenthesis,0,0);
            vector<string> ans;

            for(auto it : parenthesis){
                    string f = it;
                    int c=0;
                    int flag=0;
                    for(auto it1: f){
                        if(it1==')'){
                                if(c==0) {flag=1; break;}
                                else c--;
                        }
                        else c++;
                    }

                    if(flag==0 && c==0) ans.push_back(f); 
            }
            return ans;


    }
};