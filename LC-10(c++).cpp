class Solution {
public:
    int n,m;
    bool func(int i, int j, string &s, string &p) {
        if(i==n && j==m) return 1;
        if(j==m) return 0;
        bool flag=(i<n) && (s[i]==p[j] || p[j]=='.');
        if(j+1<m && p[j+1]=='*'){
            return func(i,j+2,s,p) || (flag && func(i+1,j,s,p));
        }
        else{
            if(flag) return func(i+1,j+1,s,p);
            else return 0;
        }
    }
    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();
        return func(0,0,s,p);
    }
};
