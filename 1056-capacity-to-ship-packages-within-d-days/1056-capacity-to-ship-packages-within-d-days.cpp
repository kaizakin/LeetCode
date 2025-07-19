class Solution {
public:

    int func(vector<int> weights,int mid){
        int days = 1,load=0;
        for(int weight:weights){
            if(load+weight > mid){
                days+=1;
                load = weight;
            }else{
                load += weight;
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low<=high){
            int mid = (low+high)/2;

            int noofdays = func(weights,mid);

            if(noofdays<=days){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return low;
    }
};