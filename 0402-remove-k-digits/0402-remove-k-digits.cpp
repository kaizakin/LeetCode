class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();

        for(int i=0; i<n; i++){
            while(!st.empty() && k>0 && st.top() - '0' > num[i] - '0'){
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        //if nothing was removed by the loop 
        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }

        //if the stack is empty return 0
        if(st.empty()) return "0";

        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        //pop all the trailing zeros coz when we reverse it'll become as leading zeroes
        while(res.size() != 0 && res.back() == '0'){
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        //what if the whole res is 0 we'd have nothing left so return 0 in that case.
        if(res.empty()) return "0";

        return res;
    }
};