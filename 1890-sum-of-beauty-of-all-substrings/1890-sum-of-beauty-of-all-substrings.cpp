class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            vector<int> chars(26,0);
            for(int j=i;j<n;j++){
                chars[s[j]-'a']++;

                int maxfreq=0,minfreq=INT_MAX;
                for(int c:chars){
                    if(c>0){
                        maxfreq = max(c,maxfreq);
                        minfreq = min(c,minfreq);
                    }
                }
                ans += maxfreq-minfreq;
            }
        }

        return ans;
    }
};