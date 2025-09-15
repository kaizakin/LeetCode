class Solution {
public:

    vector<string> ans;

    void helper(string& num, int& target, int idx, string path, long long eval, long long residual){
        if(idx == num.size()){
            if(eval == target){
                ans.push_back(path);
                return;
            }
        }

        long long currnum = 0;
        string currstr;

        for(int i = idx; i<num.size(); ++i){
            //bc
            if(i>idx && num[idx] == '0') return; // check if the starting of the current substring is 0 if it is it cannot form a proper substring. 

            currnum = currnum * 10 + num[i] - '0';
            currstr += num[i];

            if(idx == 0){
                helper(num, target, i+1, path + currstr, currnum, currnum);
            }else{
                helper(num, target, i+1, path + '+' + currstr, eval + currnum, currnum);

                helper(num, target, i+1, path + '-' + currstr, eval - currnum, -currnum);

                helper(num, target, i+1, path + '*' + currstr, eval-residual + residual*currnum, residual*currnum);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        helper(num, target, 0, "", 0, 0);

        return ans;
    }
};