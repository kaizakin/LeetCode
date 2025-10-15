class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> preMax(n);
        vector<int> sufMax(n);

        preMax[0] = height[0]; //first element
        sufMax[n-1] = height[n-1]; //last element

        for(int i = 1; i<n; i++){
            preMax[i] = max(preMax[i-1],height[i]);
        }

        for(int i = n-2; i>=0; i--){// since n-1 is already taken start from n-2
            sufMax[i] = max(sufMax[i+1],height[i]);
        }

        int total = 0;

        for(int i=0; i<n; i++){
            int leftMax = preMax[i]; 
            int rightMax = sufMax[i];

            if(height[i] < leftMax && height[i] < rightMax){
                total += min(leftMax, rightMax) - height[i];
            }
        }

        return total;
    }
};