class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int,bool> memo;

    bool solve(int idx, string& s){
        if(idx == s.size()){
            return true;
        }

        if(memo.find(idx) != memo.end()) return memo[idx];

        for(int end=idx+1;end<=s.size();end++){
            string temp = s.substr(idx,end-idx);

            if(dict.find(temp) != dict.end() && solve(end,s)){
                memo[idx] = true;
                return true;
            }
        }
        memo[idx] = false; 
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(),wordDict.end());

        if(dict.find(s) != dict.end()){
            return true;
        }

        return solve(0,s);
    }
};