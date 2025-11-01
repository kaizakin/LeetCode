class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int maxIndex = 0;
        int left = 0;
        int right = 0;
        int n = s.size();

        for(right = 0; right<n; right++){
            if(mpp.find(s[right]) == mpp.end()){ // if it doesn't exist in map.
                mpp[s[right]] = right;
                maxIndex = max(maxIndex, right-left+1);
            }else{
                if(mpp[s[right]] >= left){
                    left = mpp[s[right]] + 1;// only update if it is in the current windowd
                }
                maxIndex = max(maxIndex, right-left+1);
                mpp[s[right]] = right;
            }
        }

        return maxIndex;
    }
};