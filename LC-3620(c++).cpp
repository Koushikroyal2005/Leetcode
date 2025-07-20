#define ll long long
class Solution {
public:
    bool check(vector<vector<pair<ll,ll>>>&adj,vector<bool>&online,ll mid,ll k,ll n){
        vector<ll>dist(n,1e18);
        dist[0]=0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            ll node=pq.top().second;
            ll cost=pq.top().first;
            pq.pop();
            if(node==n-1) return cost<=k;
            for(auto it:adj[node]){
                ll v=it.first,w=it.second;
                if(cost+w<dist[v] && w>=mid && online[v]){
                    pq.push({cost+w,v});
                    dist[v]=cost+w;
                }
            }
        }
        return 0;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<ll,ll>>>adj(n);
        vector<ll>cost;
        for(auto it:edges){
            long long u=it[0],v=it[1],c=it[2];
            adj[u].emplace_back(v,c);
            cost.push_back(c);
        }
        sort(cost.begin(),cost.end());
        vector<ll>ans;
        for(ll i=0;i<cost.size();i++){
            if(ans.empty()) ans.push_back(cost[i]);
            else{
                if(ans.back()==cost[i]) continue;
                ans.push_back(cost[i]);
            }
        }
        ll s=0,e=ans.size()-1;
        ll tot=-1;
        while(s<=e){
            ll mid=(s+e)>>1;
            if(check(adj,online,ans[mid],k,n)){
                tot=ans[mid];
                s=mid+1;
            }
            else e=mid-1;
        }
        return tot;
    }
};