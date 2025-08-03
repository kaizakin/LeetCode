class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mpp={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int num=0;
        for(int i=0;i<s.size();++i){
            int curr = mpp[s[i]];
            int next = (i+1<s.size())?mpp[s[i+1]]:0;

            if(curr<next){
                num-=curr;
            }else{
                num+=curr;
            }

        }
        return num;
    }
};