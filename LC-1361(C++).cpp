class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&leftChild,vector<int>&rightChild,vector<int>&parent){
        bool left=1,right=1;
        if(leftChild[node]!=-1){
            int lchild=leftChild[node];
            if(vis[lchild]) return 0;
            vis[lchild]=1;
            if(parent[lchild]==-1){
                parent[lchild]=node;
                left=dfs(lchild,vis,leftChild,rightChild,parent);
            }
            else return 0;
        }
        if(rightChild[node]!=-1){
            int rchild=rightChild[node];
            if(vis[rchild]) return 0;
            vis[rchild]=1;
            if(parent[rchild]==-1){
                parent[rchild]=node;
                right=dfs(rchild,vis,leftChild,rightChild,parent);
            }
            else return 0;
        }
        return left && right;
    }
    bool validateBinaryTreeNodes(int n,vector<int>& leftChild,vector<int>& rightChild) {
        vector<int>vis(n,0);
        vector<int>parent(n,-1);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                if(parent[leftChild[i]]!=-1) return 0;
                parent[leftChild[i]]=i;
            }
            if(rightChild[i]!=-1){
                if(parent[rightChild[i]]!=-1) return 0;
                parent[rightChild[i]]=i;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                if(root!=-1) return 0;
                root=i;
            }
        }
        if(root==-1) return 0;
        vis[root]=1;
        fill(parent.begin(),parent.end(),-1);
        if(!dfs(root,vis,leftChild,rightChild,parent)) return 0;
        for(int i=0;i<n;i++){
            if(!vis[i]) return 0;
        }
        return 1;
    }
};