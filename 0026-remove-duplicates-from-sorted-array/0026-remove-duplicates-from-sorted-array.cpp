class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int temp=INT_MIN;
        int tracker = -1;

        for(int i=0;i<n;++i){
            if(nums[i] != temp){
                tracker++; //increment tracker only if unique item is found.
                nums[tracker]=nums[i];
                temp=nums[i];
            }
        }
        return tracker+1; //indexing starts from zero.
    }
};