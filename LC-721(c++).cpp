class disjointset{
public:
    vector<int>parent,rank,size;
    disjointset(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findparent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findparent(parent[node]);
    }
    void unionbyrank(int u,int v){
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    void unionbysize(int u,int v){
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv) return;
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjointset ds(n);
        unordered_map<string,int>hash;
        for(int i=0;i<n;i++){
            bool flag=1;
            for(auto it:accounts[i]){
                if(flag){
                    flag=0;
                    continue;
                }
                if(hash.find(it)!=hash.end()){
                    ds.unionbyrank(hash[it],i);
                }
                else{
                    hash[it]=i;
                }
            }
        }
        unordered_map<int,set<string>>check;
        for(auto &[str,ind]:hash){
            int par=ds.findparent(ind);
            check[par].insert(str);
        }
        vector<vector<string>>ans;
        for(auto &[ind,st]:check){
            vector<string>temp;
            temp.push_back(accounts[ind][0]);
            temp.insert(temp.end(),st.begin(),st.end());
            ans.push_back(temp);
        }
        return ans;
    }
};