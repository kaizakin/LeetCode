class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n = s.size();
        while(i<n && s[i]==' ') i++;

        int sign = 1;
        if(i<n && s[i]=='-'||s[i]=='+'){
            sign = s[i]=='-'?-1:1;
            i++;
        }

        long long res=0;
        while(i<n && isdigit(s[i])){
            res = res * 10 + (s[i]-'0');
            if(res*sign>=INT_MAX) return INT_MAX;
            if(res*sign<=INT_MIN) return INT_MIN;
            i++;
        }

        return (int)res*sign;
    }
};