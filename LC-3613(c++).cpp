class Solution {
public:
    void dfs(int node,vector<vector<pair<int,int>>>&adj,int mid,vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first] && it.second<=mid){
                dfs(it.first,adj,mid,vis);
            }
        }
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        int m=edges.size();
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });
        if(k>=n) return 0;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            int u=it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int s=edges[0][2],e=edges[m-1][2];
        int ans=0;
        while(s<=e){
            int mid=(s+e)>>1;
            int cnt=0,maxi=0;
            vector<int>vis(n,0);
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    cnt++;
                    dfs(i,adj,mid,vis);
                }
            }
            if(cnt>k){
                s=mid+1;
            }
            else{
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
};