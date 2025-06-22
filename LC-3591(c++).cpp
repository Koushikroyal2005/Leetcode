class Solution {
public:
    void isprime(vector<int>&prime){
        int m=prime.size();
        prime[0]=0;
        prime[1]=0;
        for(int i=0;i<m;i++){
            if(prime[i]){
                for(int j=i+i;j<m;j+=i){
                    prime[j]=0;
                }
            }
        }
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        vector<int>prime(200,1);
        isprime(prime);
        for(auto it:hash){
            if(prime[it.second]) return 1;
        }
        return 0;
    }
};