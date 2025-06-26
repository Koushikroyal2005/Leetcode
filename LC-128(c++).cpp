class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        map<int,int>hash;
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        int cnt=1,maxi=1;
        for(auto it:hash){
            if(hash.find(it.first-1)==hash.end()){
                cnt=1;
            }
            else{
                cnt++;
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};