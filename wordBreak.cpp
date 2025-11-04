class Solution {
public:
    unordered_set<string>st;
    int t[301];
    bool solve(int idx,string &s, int n){
        if(idx>=n) return true;
        if(t[idx]!=-1) return t[idx];

        //phle dekhengye s dict me h ya nhi agr h toh return nhi toh todengey
        if(st.find(s)!=st.end()){
            return t[idx]=1;
        }
        //ni mila todhna hoga 1 1 length se
        for(int l=1;l<=n;l++){
            string temp=s.substr(idx,l);
            if(st.find(temp)!=st.end() && solve(idx+l,s,n)){
                return t[idx]=1;
            }
        }
        return t[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t,-1,sizeof(t));
        for(auto &it : wordDict){
            st.insert(it);
        }
        int n=s.length();

        return solve(0,s,n);
    }
};