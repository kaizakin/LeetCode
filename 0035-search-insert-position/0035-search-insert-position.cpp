class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = 0;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target){
                ans = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        if(nums[ans] < target) ans++; //edge case of target is out of the given input.
        return ans;
    }
};