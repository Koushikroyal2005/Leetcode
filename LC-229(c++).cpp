class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el1=-1e9,el2=-1e9;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0 && el2!=nums[i]){
                cnt1++;
                el1=nums[i];
            }
            else if(cnt2==0 && el1!=nums[i]){
                cnt2++;
                el2=nums[i];
            }
            else if(el1==nums[i]) cnt1++;
            else if(el2==nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1) a++;
            if(nums[i]==el2) b++;
        }
        int tot=n/3 + 1;
        vector<int>ans;
        if(a>=tot) ans.push_back(el1);
        if(b>=tot) ans.push_back(el2);
        return ans;
    }
};