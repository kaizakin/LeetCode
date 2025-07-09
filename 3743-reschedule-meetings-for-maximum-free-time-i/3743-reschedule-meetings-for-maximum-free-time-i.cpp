class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freetime;

        freetime.push_back(startTime[0]); //free gap even before the start of the first event

        for(int i = 1;i<startTime.size();++i){
            freetime.push_back(startTime[i]-endTime[i-1]);
        }

        freetime.push_back(eventTime-endTime[endTime.size()-1]); //final free gap after all the meetings if exists

        //sliding window template
        int i = 0;
        int j = 0;
        int maxInterval = 0;
        int currSum = 0;
        int n = freetime.size();

        while(j<n){
            currSum += freetime[j];

            if(j-i+1 > k+1){ //k+1 is the window size cause if you merge two intervals you get 2+1 gaps
                currSum -= freetime[i];
                i++;
            }

            maxInterval = max(maxInterval,currSum);
            j++;
        }

        return maxInterval;
    }
};