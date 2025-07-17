class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int preSum = 0;
        int count = 0;
        unordered_map<int,int> mpp;
        mpp[0]=1;//very important if there is no presum to reduce

        for(int i=0;i<nums.size();i++){
           preSum += nums[i];
           int reduce = preSum - k;
           count += mpp[reduce];
            mpp[preSum]++;
        }
        return count;
    }
};