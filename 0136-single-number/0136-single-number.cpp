class Solution {
public:
    int singleNumber(vector<int>& nums) {
       map<int,int> freq;
       int i=0;
       for(int num : nums){
            freq[nums[i++]]++;
       } 
       int singlenumber;
       for(auto& [key,value] : freq){
            if(value<2){
                singlenumber =  key;
                break;
            }
       }
       return singlenumber;
    }
};