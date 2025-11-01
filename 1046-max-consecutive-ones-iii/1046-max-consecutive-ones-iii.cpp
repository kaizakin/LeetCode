class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int zeros = 0;

        while(r < nums.size()){
            if(nums[r] == 0) zeros++;

            if(zeros>k){
                if(nums[l] == 0) zeros--;
                l++;
            }

            if(zeros<=k) maxLen = max(maxLen, r-l+1);// only update if the number of zeros is within limit
            r++;
        }

        return maxLen;
    }
};