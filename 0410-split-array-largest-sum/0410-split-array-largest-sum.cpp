class Solution {
public:
    int splitSum(vector<int> nums,int size){
        int subarray = 1;
        long long sum = 0;
        for(int val : nums){
            if(sum+val<=size){
                sum+=val;
            }else{
                subarray++;
                sum=val;
            }
        }

        return subarray;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) return -1;

        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid = low + (high-low)/2;

            int subarraysum = splitSum(nums,mid);

            if(subarraysum>k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return low;
    }
};