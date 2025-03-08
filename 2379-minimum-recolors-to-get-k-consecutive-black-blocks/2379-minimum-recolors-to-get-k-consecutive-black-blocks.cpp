class Solution {
public:
    int minimumRecolors(string block, int k) {
        int count_black =0;
        int count_white=0;

        for(int i=0; i<k; i++){
            if(block[i]=='W') count_white++;
            else count_black++;
        }

        if(count_white==0) return 0;

        int i=0;
        int j=k;
        int ans = count_white;
        while(j<block.size()){
            if(block[j]=='W'){
                count_white++;
            }
            else count_black++;

            if(block[i]=='W'){
                count_white--;
            }
            else count_black--;

            ans=min(ans,count_white);
            j++;
            i++;
        }
        return ans;
    }
};