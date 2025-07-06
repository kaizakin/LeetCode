class FindSumPairs {
public:
    vector<int> vec1;
    vector<int> vec2;
    unordered_map<int,int> mpp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;
        for(int num: vec2){//put nums2 in map cause its large, nums1 is just 1000 at max so iteration time becomes less 
            mpp[num]++;
        }
    }
    
    void add(int index, int val) {
        mpp[vec2[index]]--;
        vec2[index] += val;
        mpp[vec2[index]]++;
    }
    
    int count(int tot) {
        int count = 0;
       for(int num: vec1){
            count += mpp[tot-num];
       } 

       return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */