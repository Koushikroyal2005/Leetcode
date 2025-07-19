struct Trie{
    unordered_map<string,Trie*>hash;
    bool flag=0;
    bool checkstring(string str){
        if(hash.find(str)!=hash.end()) return 1;
        return 0;
    }
    void put(string str,Trie* node){
        hash[str]=node;
    }
    Trie* get(string &str){
        return hash[str];
    }
    void setend(){
        flag=1;
    }
    bool isend(){
        return flag;
    }
};
class Solution {
public:
    void dfs(Trie* node,string path,vector<string>&ans){
        if(node->isend()){
            ans.push_back(path);
            return;
        }
        for(auto &[token,nextnode]:node->hash){
            dfs(nextnode,path+"/"+token,ans);
        }
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        Trie *root=new Trie();
        for(auto it:folder){
            stringstream ss(it);
            string token;
            Trie* node=root;
            while(getline(ss,token,'/')){
                if(token.empty()) continue;
                if(!node->checkstring(token)){
                    node->put(token,new Trie());
                }
                node=node->get(token);
                if(node->isend()) break;
            }
            node->setend();
            node->hash.clear();
        }
        vector<string>ans;
        dfs(root,"",ans);
        return ans;
    }
};