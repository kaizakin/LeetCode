class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size(), n2 = b.size();
        int i = 0;
        int j = 0;
        int cnt=0;
        int ind2 = (n1+n2)/2;
        int ind1 = ind2-1;
        int ind1el = INT_MIN;
        int ind2el = INT_MIN;

        while(i<n1 && j<n2){
            if(a[i] < b[j]){
                if(cnt == ind1) ind1el = a[i];
                if(cnt == ind2) ind2el = a[i];
                i++;
                cnt++;
            }else{
               if(cnt == ind1) ind1el = b[j];
                if(cnt == ind2) ind2el = b[j];
                j++;
                cnt++; 
            }
        }

        while(i< n1){
            if(cnt == ind1) ind1el = a[i];
            if(cnt == ind2) ind2el = a[i];
            i++;
            cnt++;
        }

        while(j < n2){
            if(cnt == ind1) ind1el = b[j];
            if(cnt == ind2) ind2el = b[j];
            j++;
            cnt++;
        }

        if((n1+n2)%2==1){
            return ind2el;
        }

        return (double)((double)(ind1el+ind2el))/2;
    }
};