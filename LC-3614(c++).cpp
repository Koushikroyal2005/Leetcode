class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(cnt>0) cnt--;
            }
            else if(s[i]=='%') continue;
            else if(s[i]=='#') cnt*=2;
            else cnt++;
        }
        if(cnt<=k) return '.';
        for(int i=n-1;i>=0;i--){
            //cout<<k<<" ";
            if(s[i]=='%'){
                k=cnt-1LL-k;
            }
            else if(s[i]=='#'){
                if(k>=(cnt/2)) k=k-(cnt/2);
                cnt=cnt/2;
            }
            else if(s[i]=='*') cnt++;
            else{
                if(k==cnt-1) return s[i];
                cnt--;
            }
        }
        return '.';
    }
};