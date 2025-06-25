class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>hash;
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k) ans++;
            int num=sum-k;
            if(hash.find(num)!=hash.end()){
                ans+=hash[num];
            }
            hash[sum]++;
        }
        return ans;
    }
};