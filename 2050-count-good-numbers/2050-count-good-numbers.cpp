class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long power(long long x, long long n){
        if(n==0) return 1;

        long long half = power(x,n/2);
        long long res = (half*half);
        if(n%2==1) return (res*x) % MOD;

        return res%MOD;
    }
    int countGoodNumbers(long long n) {
       long long evencount = (n+1)/2;
       long long oddcount = n/2;

       long long res = (power(5, evencount) * power(4, oddcount)) % MOD;  
       return (int)res;
    }
};