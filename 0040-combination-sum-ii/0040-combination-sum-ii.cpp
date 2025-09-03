class Solution {
public:
     void solve(vector<int>& candidates, int target, vector<int>& curr, vector<vector<int>>& res, int idx){
        
        if(target == 0){
            res.push_back(curr);
            return;
        }

        for(int i = idx;i<candidates.size();i++){

            if(i > idx && candidates[i] == candidates[i-1]){
                continue; //duplicate detected so dont return/ break just skip this iteration
            }

            if(candidates[i] > target) break; //there is no leave it condition since the vector is sorted


            curr.push_back(candidates[i]);
            solve(candidates,target - candidates[i],curr,res,i+1); 
            curr.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end()); //always a good idea to sort the array when detecting duplicates
        vector<vector<int>> res;
        vector<int> curr;
        solve(candidates, target, curr, res, 0);

        return res;
    }
};