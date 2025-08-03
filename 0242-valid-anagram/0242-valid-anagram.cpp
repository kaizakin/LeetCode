class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char,int> s1,s2;
        
        for(int i=0;i<s.size();++i){
            s1[s[i]]++;
            s2[t[i]]++;
        }

        return s1==s2;
    }
};