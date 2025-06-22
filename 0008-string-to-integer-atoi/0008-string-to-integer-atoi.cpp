class Solution {
public:
    int myAtoi(string s) {
        long long int g = 0;
        int n = s.size();
        int flag = 0;
        int flag2 = 0;
        int r1 = pow(2,31)-1;
        for(int i=0; i<n; i++)
        {
            int x = s[i]-'0';
            if(x>=0 && x<=9)
            {
                cout<<x<<endl;
                flag++;
                g=(g*10);
                g=g+x;
                if(g>r1) break;
            }
            else if (s[i]=='-')
            {
                if(flag==0 && flag2==0) flag2++;
                else break;
            }
            else if(s[i]=='+'){ if(flag2>0 || flag>0) break;  flag++;}
            else if (s[i]==' '){if(flag>0) break;}
            else
            {
                break;
            }
        }
        int r = -pow(2,31);
        
        cout<<g<<endl;
        if(flag2>0)
        {
            long long y = -g;
            if(y<r) return r;
            return y;
        }
        else 
        {
            if(g>r1) return r1;
            return g;
        }
        return g;
    }
};