#define ll long long
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n=nums.size();
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        ll q=target/sum;
        ll rem=target%sum;
        if(rem==0){
            return n*q;
        }
        for(ll i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        ll i=0,j=0;
        ll tot=0,ans=1e9;
        while(i<nums.size()){
            tot+=nums[i];
            while(tot>rem){
                tot-=nums[j];
                j++;
            }
            if(tot==rem){
                ans=min(ans,i-j+1);
            }
            i++;
        }
        if(ans==1e9) return -1;
        return  n*q+ans;
    }
};