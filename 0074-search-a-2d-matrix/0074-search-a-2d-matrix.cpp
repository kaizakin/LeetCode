class Solution {
public:
    int func(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1; 
        while (left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;

            if (nums[mid] < target) {
                left = mid + 1; 
            } else {
                right = mid-1; 
            }
        }
        return right;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> first_col;
        for(auto& row: matrix){
            first_col.push_back(row[0]);
        }

        for(int num : first_col){
            cout<<num<<endl;
        }
        int index = func(first_col,target);
        cout<<index<<endl;
        if(index == -1) return false;

        int low = 0, high = matrix[0].size()-1; 

        while(low<=high){
            int mid = (low+high)/2;

            if(matrix[index][mid] == target) return true;

            if(matrix[index][mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return false;
    }
};