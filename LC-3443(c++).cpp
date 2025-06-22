class Solution {
public:
    int maxDistance(string s, int k) {
        int n1=s.size();
        int ans=0;
        int n=0,s1=0,e=0,w=0;
        for(int i=0;i<n1;i++){
            if(s[i]=='N') n++;
            if(s[i]=='S') s1--;
            if(s[i]=='E') e++;
            if(s[i]=='W') w--;
            ans=max(ans,min(abs(n+s1)+abs(e+w)+k*2,i+1));
        }
        return ans;
    }
};