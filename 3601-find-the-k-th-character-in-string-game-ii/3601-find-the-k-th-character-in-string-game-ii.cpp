class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1) return 'a';

       long long len = 1;
       long long newK = -1;
       int operationsType = -1;
       int n = operations.size();

       for(int i=0;i<n;i++){
            len *= 2;
            if(len>=k){
                 operationsType = operations[i];
                 newK = k - len/2;
                 break;
            }
       }
       char ch = kthCharacter(newK,operations);

       if(operationsType==0){
        return ch;
       }else{
        return ch == 'z'? 'a' : ch+1;
       }

    }
};