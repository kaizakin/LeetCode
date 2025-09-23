class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> list;
        int subsets = 1<<nums.size();

        for(int i = 0; i<subsets; ++i){
            vector<int> temp;
            for(int j = 0; j<n; ++j){
                if(i & (1<<j))
                    temp.push_back(nums[j]);
            }
            list.push_back(temp);
        }

        return list;
    }
};