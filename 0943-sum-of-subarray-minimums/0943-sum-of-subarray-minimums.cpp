class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> left(n),right(n);
        stack<pair<int,int>> st1,st2;


        //calculate left mins
        for(int i = 0; i<n; i++){
            int cnt = 1;

            while(!st1.empty() && st1.top().first > arr[i]){
                cnt += st1.top().second;
                st1.pop();
            }

            st1.push({arr[i],cnt});
            left[i] = cnt;
        }


        //calculate right mins
        for(int i = n-1; i>=0; i--){
            int cnt = 1;

            while(!st2.empty() && st2.top().first >= arr[i]){ //>= in right alone ensures equal element are counted only once
                cnt += st2.top().second;
                st2.pop();
            }

            st2.push({arr[i],cnt});
            right[i] = cnt;
        }

        int ans = 0;
        for(int i=0;i<n; i++){
            ans = (ans + (long long)arr[i] * left[i] * right[i]) % MOD;
        }

        return ans;
    }
};