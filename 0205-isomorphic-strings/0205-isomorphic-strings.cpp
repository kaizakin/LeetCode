class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char,char> stot, ttos;

        for(int i=0;i<s.size();++i){
            char ch1 = s[i];
            char ch2 = t[i];

            if(stot.count(ch1) && stot[ch1]!=ch2){
                return false;
            }
            
            if(ttos.count(ch2) && ttos[ch2]!=ch1){
                return false;
            }

            stot[ch1]=ch2;
            ttos[ch2]=ch1;
        }

       return true; 
    }
};