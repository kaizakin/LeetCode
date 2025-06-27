class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currfrequency = 0,maxfrequency = 0;
        for(int num : nums){
            if(num == 1){
                currfrequency++;
                maxfrequency = max(currfrequency,maxfrequency);
            }
            else{
                currfrequency = 0;
            }
        }
        return maxfrequency;
    }
};