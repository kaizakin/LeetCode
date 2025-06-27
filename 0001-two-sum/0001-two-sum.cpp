class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> complementstorage;
        vector<int> ans;
        for(int i=0;i<n;++i){
            int complement = target - nums[i];
            if(complementstorage.find(complement)!=complementstorage.end()){
                ans = {i,complementstorage[complement]};
            }
            complementstorage[nums[i]] = i; 
        }
        return ans;
    }
};