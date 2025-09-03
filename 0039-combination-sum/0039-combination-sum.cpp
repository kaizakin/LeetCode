class Solution {
public:

    void solve(vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& res, int idx){
        
        if(target == 0){
            res.push_back(curr);
            return;
        }

        if(idx >= candidates.size()){
            return;
        }

        if(candidates[idx] <= target){
            curr.push_back(candidates[idx]);
            solve(candidates,target - candidates[idx],curr,res,idx); //don't move the index as we can reuse the element.
            curr.pop_back();
        }

        solve(candidates,target,curr,res,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        solve(candidates,target,curr,res,0);
        return res;
    }
};