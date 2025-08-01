class Solution {
public:
    int maxInd(vector<vector<int>>mat,int n,int m,int mid){
        int maxval = -1;
        int index = -1;
        for(int i=0;i<n;i++){
            if(mat[i][mid] > maxval){
                maxval = mat[i][mid];
                index = i;
            }
        }

        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;

        while(low<=high){
            int mid = (low+high)/2;
            int maxrowInd = maxInd(mat,n,m,mid); 
            int left = mid-1 >= 0 ? mat[maxrowInd][mid-1] : -1;
            int right = mid+1 < m ? mat[maxrowInd][mid+1] : -1;

            if(mat[maxrowInd][mid]>left && mat[maxrowInd][mid]>right ){
                return {maxrowInd,mid}; //this might be the one.
            }else if(mat[maxrowInd][mid] < left){
                high = mid-1; //left is bigger bro
            }else{
                low = mid+1;
            }
        }

        return {-1,-1};
    }
};