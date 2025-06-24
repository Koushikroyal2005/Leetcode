class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int num=nums[0];
        for(int i=1;i<n;i++){
            num=num^nums[i];
        }
        for(int i=0;i<=n;i++){
            num=num^i;
        }
        return num;
    }
};