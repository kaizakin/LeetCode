class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int prev = INT_MIN;
        int after = INT_MIN;
        int ansindex = -1;

        while(left<=right){
            int mid = (left+right)/2;
            if(mid==0){
                prev = INT_MIN;
            }else{
                prev = arr[mid-1];
            }
            if(mid == n-1){
                after = INT_MIN;
            }else{
                after = arr[mid+1];
            }

            if(arr[mid]>=prev && arr[mid]>=after){
                ansindex = mid;
            }

            if(arr[mid] >= prev){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        return ansindex;
    }
};