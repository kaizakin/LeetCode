class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(char ch:s){
            mpp[ch]++;
        }

        priority_queue<pair<int,char>> maxheap;

        for(auto &[c,f]:mpp){
            maxheap.push({f,c});
        }
        string res = "";
        while(!maxheap.empty()){
            auto [f,c] = maxheap.top(); maxheap.pop();
            res+=string(f,c); //repeat c ftimes
        }

        return res;
    }
};