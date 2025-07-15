class Solution {
public:
    long long func(vector<int> piles,int mid){
        long long totalHrsToEat=0;
        for(int i: piles){
            totalHrsToEat += ceil((double)i/(double)mid); //doing ceil to an integer makes no sense so type case it.
        }

        return totalHrsToEat;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid = (low+high)/2;

            long long timeToEat = func(piles,mid);

            if(timeToEat <= h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return low;
    }
};