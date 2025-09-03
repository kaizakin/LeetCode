class Solution {
public:
    void solve(vector<int> &nums,int idx,vector<vector<int>> &res,vector<int> &temp){
        if(idx >= nums.size()){
            res.push_back(temp);
            return; 
        }

        temp.push_back(nums[idx]);//take it
        solve(nums,idx+1,res,temp);
        temp.pop_back();
        solve(nums,idx+1,res,temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;

        solve(nums,0,res,temp);
        return res;
    }
};