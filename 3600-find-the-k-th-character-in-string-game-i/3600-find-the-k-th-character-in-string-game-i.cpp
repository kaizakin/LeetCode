class Solution {
public:
    char kthCharacter(int k) {
       string word = "a";
       while(word.length()<k){
        int n = word.length();
        for(int i=0;i<n;++i){
            char c = word[i]=='z'?'a':word[i]+1;
            word.push_back(c);
        }
       }
       return word[k-1];
    }
};