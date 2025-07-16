class Solution {
public:
    int func(vector<int> nums,int mid){
        int sum = 0;
        for(int num:nums){
            sum += ceil((double)num/(double)mid);
            // cout<<"sum "<<num<<" "<<sum<<endl;
        }
        // cout<<endl;
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = INT_MAX;
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        while(low<=high){
            int mid = (low+high)/2;
            // cout<<"mid "<<mid<<endl;

            int sum = func(nums,mid);
            if(sum <= threshold){
                ans = min(mid,ans);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};