class Solution {
public:
    int majorityElement(vector<int>& n) {
        int n1=n.size();

        int count=0;
        int element=-1;

        for(int i=0; i<n1; i++)
        {
            if(n[i]==element)
            {
                count++;
            }
            else 
            {
                if(count==0){
                element=n[i]; count++;}
                else count--;
                
            }
        }
        return element;
    }
};