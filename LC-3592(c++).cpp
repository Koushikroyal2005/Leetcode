class Solution {
public:
    vector<int> findCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>hash(n+1,0);
        hash[0]=1;
        vector<int>ans;
        for(int i=1;i<=n;i++){
            int cnt=hash[i];
            if(cnt<nums[i-1]){
                ans.push_back(i);
                for(int j=i;j<=n;j++){
                    hash[j]+=hash[j-i];
                }
                if(hash[i]!=nums[i-1]) return {};
            }
            else if(cnt>nums[i-1]){
                return {};
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};