class Solution {
public:
    vector<string> res;
    unordered_map<char, string> mpp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solve(string &digits,string &curr, int idx){
        if(idx>=digits.size()){
            res.push_back(curr);
            return;
        }

        char ch = digits[idx];
        string str = mpp[ch];

        for(int i=0;i<str.size();i++){
            curr.push_back(str[i]);
            solve(digits, curr, idx+1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        string curr = "";

        solve(digits,curr,0);

        return res;
    }
};