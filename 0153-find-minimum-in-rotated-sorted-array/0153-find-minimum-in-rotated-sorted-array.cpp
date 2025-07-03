class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int left = 0;
        int right = n - 1;
        int minvalue = 5001;
      
        while (left <= right) {
            int mid = left + (right - left) / 2;
            minvalue = min(nums[mid], minvalue);
            cout << "min" << minvalue << endl;
            cout << "mid" << nums[mid] << endl;

            if (nums[left] <= nums[mid]) {
                if (mid - 1 >= 0) {
                    minvalue = min(minvalue, nums[left]);
                }
                left = mid + 1;
            } else {
                if (mid + 1 < n) {

                    minvalue = min(nums[mid + 1], minvalue);
                    right = mid - 1;
                }
            }
        }
        return minvalue;
    }
};