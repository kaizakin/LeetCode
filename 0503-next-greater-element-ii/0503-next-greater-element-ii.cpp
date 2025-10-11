class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> nge(n);

        //imagine the array is doubled
        for(int i=2*n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                //if the top element is less than the current element we pop to ensure monotonicity

                st.pop();
            }

            if(i<n){
                nge[i] = st.empty() ? -1 : st.top();
            }

            st.push(nums[i%n]); //push the current element to the stack so that the next elements could use it.
        }

        return nge;
    }
};