class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int e = numBottles;
        numBottles=0;

        while((e+numBottles)>=numExchange)
        {
            if(e>=numExchange)
            {
                e-=numExchange;
                numBottles++;
                numExchange++;
            }
            else
            {
                ans+=numBottles;
                e+=numBottles;
                numBottles=0;
            }
        }
        return ans+numBottles;
    }
};