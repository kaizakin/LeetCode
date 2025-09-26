class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;

        vector<bool> bucket(n,true);
        bucket[0]=bucket[1]=false;

        for(int i=2; i*i<n; i++){
            if(bucket[i]){
                for(long j=i*i; j<n; j+=i){ //what if i*i exceeds int range
                    bucket[j] = false;
                }
            }
        }
        
        int cnt = count(bucket.begin(),bucket.end(),true);
        return cnt;
    }
};