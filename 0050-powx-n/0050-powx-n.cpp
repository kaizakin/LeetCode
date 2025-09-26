class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        double ans = 1.00;

        //if the n is negative do a reciprocal and compute power which is the same as computing negative power 2^-3 = 1/2^3
        if(exp<0){
            x = 1/x;
            exp = -exp; //convert it to positive since we did reciprocal
        }


        while(exp>0){
            if(exp % 2 == 1){
                ans = ans * x;
                exp -= 1;
            }else{
                x = x*x;
                exp /= 2;
            }
        }

        return ans;
    }
};