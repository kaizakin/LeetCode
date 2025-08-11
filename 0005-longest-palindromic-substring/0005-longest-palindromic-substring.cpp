class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if(n<=1){
            return s;
        }

        int len = 0;
        int maxlen = 1;
        int start=0;

        auto palindrome = [&](int left,int right){
            while(left>=0 && right<n && s[left]==s[right]){
                len = (right-left)+1;
                if(len>maxlen){
                    maxlen=len;
                    start=left;
                }
            left--;
            right++; //increase the window
            }
        }; //nested functions in c++ is not possible so we use lambda functions

        for(int i=0;i<n;++i){
            palindrome(i,i);//if the string length is odd
            palindrome(i,i+1);//if the string length is even
        }

        return s.substr(start,maxlen);
    }
};