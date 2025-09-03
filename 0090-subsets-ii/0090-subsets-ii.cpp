class Solution {
public:
    void solve(vector<int> &nums,int idx,vector<vector<int>> &res,vector<int> &temp){
        res.push_back(temp);
        
        for(int i = idx;i<nums.size();i++){
           if(i>idx && nums[i]==nums[i-1]){
            continue;
           }

           temp.push_back(nums[i]);//take it
            solve(nums,i+1,res,temp);
            temp.pop_back(); //there is no need for leave it condition since we are omitting duplicates
        }
        

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> res;
        vector<int> temp;

        solve(nums,0,res,temp);

        return res;
    }
};