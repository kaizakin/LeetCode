class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return "";
        string initString = strs[0];

        for(int i=0;i<initString.size();++i){
            int ch = initString[i];
            for(int j=1;j<strs.size();++j){
                if(i>=strs[j].size()||strs[j][i]!=ch){
                    return initString.substr(0,i);
                }
            }
        }

        return initString;
    }
};