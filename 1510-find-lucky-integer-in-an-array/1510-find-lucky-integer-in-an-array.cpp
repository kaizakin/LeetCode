class Solution {
public:
    int findLucky(vector<int>& arr) {
        int lucky = -1;
        int n = arr.size();
       unordered_map<int,int> mpp;
       for(int i=0;i<n;++i){
            mpp[arr[i]]++;
       } 
       for(auto it: mpp){
        if(it.first == it.second){
            lucky = max(lucky,it.second);
        }
       }
       return lucky;
    }
};