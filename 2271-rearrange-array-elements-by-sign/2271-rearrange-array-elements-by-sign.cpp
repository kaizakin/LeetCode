class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int positive = 0;
        int negative = 1;

        for(int num : nums){
            if(num > 0){
                result[positive] = num;
                positive += 2;
            }else{
                result[negative] = num;
                negative += 2;
            }
        }
        return result;

    }
};