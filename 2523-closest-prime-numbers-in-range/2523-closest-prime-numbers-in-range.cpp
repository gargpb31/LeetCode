class Solution {
public:
 const int N = 1e6 + 1;
    vector<bool> is_prime;

    Solution() : is_prime(N, true) { 
        Sieve();
    }


 void Sieve(){
is_prime[0]=is_prime[1]=false;
for(int i=0;i<N;i++){
if(is_prime[i]==true){
for(int j=2*i;j<N;j+=i){
is_prime[j]=false;
}
}
}
}
    vector<int> closestPrimes(int left, int right) {
        int t1=-1;
        int t2=-1;
        while(left<=right){
            if(is_prime[left]){
                if(t1==-1) {
                    t1=left;
                }
                else if(t2==-1){
                    t2=left;
                }
                else{
                    if((t2-t1)>(left-t2)){
                        t1=t2;
                        t2=left;
                    }
                }
            }
            left++;
        }
        if(t2==-1) t1=-1;
        
        return {t1,t2};
    }
};