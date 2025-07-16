class Solution {
public:
    int func(vector<int> bloomDay,int mid,int k){
        int count = 0;
        int ans = 0;
        for(int day:bloomDay){
            if(day<=mid){
                count++;
            }else{
                ans += (count/k);
                count=0;
            }
        }
        ans += (count/k);
        return ans;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int nodays = INT_MAX;
        int left = 1;
        int right = *max_element(bloomDay.begin(),bloomDay.end());

        while(left<=right){
            int mid = (left+right)/2;
            cout<<"mid "<<mid<<endl;
            int numBoquetsFormed = func(bloomDay,mid,k);
            cout<<numBoquetsFormed<<endl;

            if(numBoquetsFormed < m){
                left = mid+1;
            }else{
                nodays = min(mid,nodays);
                right = mid-1;
            }
        }

        return nodays == INT_MAX ? -1 : nodays;
    }
};