class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1,i=0;
        while(i<=r){
            if(nums[i]==0){
                swap(nums[i],nums[l]);
                i++;
                l++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[r]);
                r--;
            }
            else i++;
        }
    }
};