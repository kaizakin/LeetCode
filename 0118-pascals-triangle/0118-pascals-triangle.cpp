class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> genmatrix;
    for(int i=0;i<numRows;i++){
        vector<int> row(i+1,1);
        for(int j=0;j<i+1;j++){
            if(j > 0 && j<i){
                row[j] = genmatrix[i-1][j-1] + genmatrix[i-1][j];
            }
        }
        genmatrix.push_back(row);
    }
    return genmatrix;
    }
};