class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size() == 1) return true;//edge case 

        int noofdrops = 0;
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(nums[i] > nums[(i+1)%n]){
                noofdrops++;
            }
        }
        return noofdrops<=1;
    }
};