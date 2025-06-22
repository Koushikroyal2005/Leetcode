class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int mini=nums[0][0],maxi=nums[0][0];
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i][0]);
            maxi=max(maxi,nums[i][0]);
            pq.push({nums[i][0],{i,0}});
        }
        vector<int>ans={mini,maxi};
        while(true){
            auto it=pq.top();
            pq.pop();
            int num=it.first,ind=it.second.first,i=it.second.second;
            i++;
            if(i>=nums[ind].size()){
                break;
            }
            int nextnum=nums[ind][i];
            maxi=max(maxi,nextnum);
            pq.push({nextnum,{ind,i}});
            mini=pq.top().first;
            if(maxi-mini<ans[1]-ans[0]){
                ans[1]=maxi;
                ans[0]=mini;
            }
        }
        return ans;
    }
};