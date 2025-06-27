class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int a=0,b=0;
        priority_queue<int,vector<int>,greater<int>>odds,evens;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                a++;
                evens.push(i);
            } 
            else{
                b++;
                odds.push(i);
            }
        }
        if(abs(a-b)>1) return -1;
        if(a>b){
            int cnt=0,i=0;
            while(!evens.empty()){
                cnt+=abs(evens.top()-i);
                evens.pop();
                i+=2;
            }
            return cnt;
        }
        else if(b>a){
            int cnt=0,i=0;
            while(!odds.empty()){
                cnt+=abs(odds.top()-i);
                odds.pop();
                i+=2;
            }
            return cnt;
        }
        else{
            int cnt1=0,i=0;
            priority_queue<int,vector<int>,greater<int>>evens1=evens;
            while(!evens1.empty()){
                cnt1+=abs(evens1.top()-i);
                evens1.pop();
                i+=2;
            }
            int cnt2=0;
            i=0;
            priority_queue<int,vector<int>,greater<int>>odds1=odds;
            while(!odds1.empty()){
                cnt2+=abs(odds1.top()-i);
                odds1.pop();
                i+=2;
            }
            return min(cnt1,cnt2);
        }
    }
};
