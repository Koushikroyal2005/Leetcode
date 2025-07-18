class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int cnt=0;
        vector<int>arr(n+1);
        for(int i=0;i<ranges.size();i++){
            int mini=i-ranges[i];
            int maxi=i+ranges[i];
            if(mini<0) mini=0;
            if(maxi>n) maxi=n;
            arr[mini]=max(arr[mini],maxi);
        }
        int maxi=0,prev=0;
        for(int i=0;i<=n;i++){
            if(i>maxi) return -1;
            if(i>prev){
                cnt++;
                prev=maxi;
            }
            maxi=max(maxi,arr[i]);
        }
        return cnt;
    }
};