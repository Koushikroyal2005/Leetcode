class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int i=0;
        while(i<n){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
            i++;
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};