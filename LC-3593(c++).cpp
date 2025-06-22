#define ll long long
class Solution {
public:
    ll cnt=0;
    void dfs(ll node,vector<vector<ll>>&adj,vector<int>&cost,ll sum,vector<ll>&maxi,vector<ll>&vis){
        for(auto it:adj[node]){
            vis[node]=1LL;
            dfs(it,adj,cost,sum+1LL*cost[node],maxi,vis);
        }
        if(!vis[node]){
            maxi[node]=sum+1LL*cost[node];
        }
    }
    void dfs1(ll node,ll p,vector<vector<ll>>&adj,vector<int>&cost,ll sum,vector<ll>&vis1,ll leafmax,vector<ll>&arr){
        for(auto it:adj[node]){
            vis1[node]=1LL;
            dfs1(it,node,adj,cost,sum+1LL*cost[node],vis1,leafmax,arr);
        }
        if(!vis1[node]){
            //arr[p]=min(arr[p],sum+cost[node]);
            arr[node]=sum+1LL*cost[node];
            return;
        }
        ll mini=1e15;
        for(auto it:adj[node]){
            if(!vis1[it]) mini=min(mini,leafmax-arr[it]);
            else mini=min(mini,arr[it]);
        }
        for(auto it:adj[node]){
            if(!vis1[it]){
                if(leafmax-arr[it]>mini) cnt++;
            }
            else{
                if(arr[it]>mini) cnt++;
            }
        }
        arr[node]=mini;
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<ll>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<ll>maxi(n+1,0);
        vector<ll>vis(n+1,0);
        dfs(0,adj,cost,0,maxi,vis);
        ll leafmax=*max_element(maxi.begin(),maxi.end());
        vector<ll>vis1(n+1,0);
        vector<ll>arr(n+1,1e9);
        dfs1(0LL,0LL,adj,cost,0LL,vis1,leafmax,arr);
        return cnt;
    }
};