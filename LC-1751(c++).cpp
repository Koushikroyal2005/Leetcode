class Solution {
public:
    vector<int>next;
    long long func(int i,vector<vector<int>>&events,int k,int prev,vector<vector<long long>>&dp){
        if(k==0 || i==events.size()) return 0LL;
        if(dp[i][k]!=-1LL) return dp[i][k];
        long long take=0;
        if(events[i][0]>prev){
            take=events[i][2]+func(next[i],events,k-1,events[i][1],dp);
        }
        long long nottake=func(i+1,events,k,prev,dp);
        return dp[i][k]=max(take,nottake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        // memoization
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,-1LL));
        for(int i=0;i<n;i++){
            int ind=upper_bound(events.begin(),events.end(),vector<int>{events[i][1]+1,0,0})-events.begin();
            next.push_back(ind);
        }
        return func(0,events,k,-1,dp);

        // tabulation
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,0LL));
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                long long take=events[i][2]+dp[next[i]][j-1];
                long long nottake=dp[i+1][j];
                dp[i][j]=max(take,nottake);
            }
        }
        return dp[0][k];
    }
};