class Solution {
public:

    vector<vector<int>> res;
    void solve(int k, int n, int start, vector<int> &curr){
        if(n==0 && curr.size()==k){
            res.push_back(curr);
            return;
        }

        if(n < 0 || curr.size() > k) return;


        for(int i=start;i<=9;++i){
            curr.push_back(i);
            solve(k,n-i,i+1,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;

        solve(k,n,1,curr);

        return res;
    }
};