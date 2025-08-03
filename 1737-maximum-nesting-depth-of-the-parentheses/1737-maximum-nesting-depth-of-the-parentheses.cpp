class Solution {
public:
    int maxDepth(string s) {
       int maxDepth = 0;
       int currDepth = 0;
       for(char ch:s){
        if(ch=='('){
            currDepth++;
            maxDepth = max(currDepth,maxDepth);
        }else if(ch==')'){
            currDepth--;
        }
       } 

       return maxDepth;
    }
};