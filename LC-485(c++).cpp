class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0,maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=1) ans=0;
            else{
                ans++;
                maxi=max(maxi,ans);
            }
        }
        return maxi;
    }
};