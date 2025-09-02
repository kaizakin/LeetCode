class Solution {
public:
    void solve(string curr,int open,int close,int n,vector<string> &vc){
        if(curr.size() == n*2){
            vc.push_back(curr);
            curr="";
            return;
        }

        if(open < n){
            solve(curr+'(',open+1,close,n,vc);
        }

        if(close<open){
            solve(curr+')',open,close+1,n,vc);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vc;

        solve("",0,0,n,vc);

        return vc;
    }
};