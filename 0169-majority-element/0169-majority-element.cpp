class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for(int num : nums){
            if(count==0){
                candidate = num; //if count is 0 reset the candidate
            }
            count += (candidate==num) ? 1 : -1;
        }
        return candidate;
    }
};