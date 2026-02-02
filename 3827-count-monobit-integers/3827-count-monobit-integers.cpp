class Solution {
public:
    int countMonobit(int n) {
        int count = 1;
        int x = 1;
        int i=1;
        while(x<=n)
        {
            count++;
            x+=(pow(2,i));
            i++;
        }
        return count;
    }
};