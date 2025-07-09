class Solution {
public:
    void func(string word, string start,unordered_map<string, vector<string>>& hashmap,vector<vector<string>>& ans, vector<string>& path){
        if(word==start){
            path.push_back(start);
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            path.pop_back();
            return;
        }
        path.push_back(word);
        for(auto& it:hashmap[word]){
            func(it,start,hashmap,ans,path);
        }
        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>hash(wordList.begin(), wordList.end());
        if(!hash.count(endWord)) return {};
        unordered_map<string,vector<string>>hashmap;
        unordered_set<string>visited;
        queue<string>qt;
        qt.push(beginWord);
        visited.insert(beginWord);
        bool flag=false;
        while(!qt.empty() && !flag){
            int size=qt.size();
            unordered_set<string>level;
            while(size--){
                string word=qt.front(); 
                qt.pop();
                string original=word;
                for(int i=0;i<word.length();i++){
                    char old=word[i];
                    for(char ch='a';ch<='z';ch++){
                        word[i]=ch;
                        if(hash.count(word) && !visited.count(word)){
                            if(word==endWord) flag=true;
                            hashmap[word].push_back(original);
                            if(!level.count(word)){
                                qt.push(word);
                                level.insert(word);
                            }
                        }
                    }
                    word[i]=old;
                }
            }
            for(auto& it:level){
                visited.insert(it);
            }
        }
        vector<vector<string>>ans;
        if(flag){
            vector<string>path;
            func(endWord,beginWord,hashmap,ans,path);
        }
        return ans;
    }
};