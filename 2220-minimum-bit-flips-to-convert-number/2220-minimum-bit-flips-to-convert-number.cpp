class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int d = __builtin_popcount(ans);
        return d;
    }
};