class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for(int i=0; i<n; i++){
            // if you found ia smaller element the the top element in the stack
            while(!st.empty() && heights[st.top()] > heights[i]){
                int index = st.top(); st.pop();
                int pseindex = st.empty() ? -1 : st.top(); // the pse is the next element in the stack
                int nseindex = i; // nse is current index
                maxArea = max(heights[index] * (nseindex - pseindex - 1), maxArea); // next - prev -1
            }
            // we are pushing the index
            st.push(i);
        }

        // if there are any leftouts in the stack
        while(!st.empty()){
            int index = st.top(); st.pop();
            int nseindex = n; //coz these don't have a nse so the hypothetical last index
            int pseindex = st.empty() ? -1 : st.top();
            maxArea = max(heights[index] * (nseindex - pseindex - 1), maxArea);
        }

        return maxArea;
    }
};