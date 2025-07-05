class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        if(nums[0]!=nums[1]) return nums[0]; //take care of the edge cases in the beginning
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        
        int left = 1;
        int right = n-2;

        while(left<=right){
            int mid = left + (right-left)/2;

            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid]; // this is where the edge cases come into picture

            if(mid%2==0 && nums[mid]==nums[mid+1] || mid%2==1 && nums[mid]==nums[mid-1]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        
        return -1;

    }
};