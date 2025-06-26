class Solution {
public:
    void merge(int s ,int mid,int mid1,int e,vector<int>&nums){
        vector<int>temp;
        int l=s,r=mid1;
        while(l<=mid && r<=e){
            if(nums[l]<=nums[r]){
                temp.push_back(nums[l++]);
            }
            else temp.push_back(nums[r++]);
        }
        while(l<=mid){
            temp.push_back(nums[l++]);
        }
        while(r<=e){
            temp.push_back(nums[r++]);
        }
        for(int i=s;i<=e;i++){
            nums[i]=temp[i-s];
        }
    }
    int countpairs(int s,int mid,int mid1,int e,vector<int>&nums){
        int tot=0;
        int j=mid1;
        for(int i=s;i<=mid;i++){
            while(j<=e && nums[i]>2LL*nums[j]) j++;
            tot+=(j-mid1);
        }
        return tot;
    }
    int mergesort(int s,int e,vector<int>&nums){
        if(s>=e) return 0;
        int mid=(s+e)>>1;
        int cnt=0;
        cnt+=mergesort(s,mid,nums);
        cnt+=mergesort(mid+1,e,nums);
        cnt+=countpairs(s,mid,mid+1,e,nums);
        merge(s,mid,mid+1,e,nums);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int ans=mergesort(0,n-1,nums);
        return ans;
    }
};