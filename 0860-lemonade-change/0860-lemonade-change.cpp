class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int c_5 = 0 ,c_10=0,c_20=0;

        int bills_size = bills.size();

        for(int i=0; i<bills_size; i++)
        {
           if(bills[i]==5) c_5++;
           else if (bills[i]==10)
           {
            if(c_5>0) c_5--;
            else return false;
            c_10++;
           }
           else
           {
            c_20++;
            if(c_10>0 && c_5>0)
            {
                c_10--;
                c_5--;
            }
            else if (c_5>=3)
            {
                c_5-=3;
            }
            else return false;
           }
        }
        return true;
    }
};