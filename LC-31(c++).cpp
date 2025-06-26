class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        bool flag=1;
        int num,ind;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                flag=0;
                ind=i;
                num=nums[i];
            }
        }
        if(flag){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=i;i--){
            if(nums[i]>num){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
    }
};