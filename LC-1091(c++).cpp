class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        dist[0][0]=1;
        queue<pair<int,int>>qt;
        qt.push({0,0});
        vector<int>dx={-1,1,0,0,-1,1,-1,1};
        vector<int>dy={0,0,-1,1,1,1,-1,-1};
        while(!qt.empty()){
            auto it=qt.front();
            qt.pop();
            int r=it.first,c=it.second;
            int dis=dist[r][c];
            for(int i=0;i<8;i++){
                int nr=r+dx[i],nc=c+dy[i];
                if(0<=nr && nr<n && 0<=nc && nc<n && grid[nr][nc]==0 && dis+1<dist[nr][nc]){
                    dist[nr][nc]=dis+1;
                    qt.push({nr,nc});
                }
            }
        }
        return dist[n-1][n-1]==1e9 ? -1:dist[n-1][n-1];
    }
};