class Solution {
public:
    void flip(vector<int>& nums,int start,int end){
        while(start<end){
            swap(nums[start++],nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        if(k==0)return;
       int n = nums.size();
       k%=n; //finding the starting position of the flipped array.

        flip(nums,0,n-1); //flip the entire array
        flip(nums,0,k-1); //now individually flip the left part and the right part of the array.
        flip(nums,k,n-1);
    }
};