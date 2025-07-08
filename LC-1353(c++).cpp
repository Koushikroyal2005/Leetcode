class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        int t=1;
        int ans=0;
        while(i<n || !pq.empty()){
            if(pq.empty()) t=max(t,events[i][0]);
            while(i<n && t==events[i][0]){
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top()<t){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
            t++;
        }
        return ans;
    }
};