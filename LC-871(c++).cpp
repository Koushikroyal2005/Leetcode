class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        priority_queue<int>pq;
        int cnt=0;
        for(int i=0;i<n;i++){
            int pos=stations[i][0];
            int fuel=stations[i][1];
            if(startFuel<pos){
                while(!pq.empty() && startFuel<pos){
                    startFuel+=pq.top();
                    cnt++;
                    pq.pop();
                }
                if(startFuel<pos) return -1;
            }
            pq.push(fuel);
            if(startFuel>=target) return cnt;
        }
        while(!pq.empty() && startFuel<target){
            startFuel+=pq.top();
            pq.pop();
            cnt++;
        }
        if(startFuel<target) return -1;
        return cnt;
    }
};