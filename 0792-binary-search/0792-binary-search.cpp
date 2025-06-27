class Solution {
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        if(left>right) return -1;  

        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] > target) {
            return binarySearch(nums, left, mid-1, target);
        } else {
            return binarySearch(nums, mid+1, right , target);
        }
    }

public:
    int search(vector<int>& nums, int target) {
        int ans;
        ans = binarySearch(nums, 0, nums.size() - 1, target);
        return ans;
    }
};