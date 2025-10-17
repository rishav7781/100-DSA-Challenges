class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;

        int i=0;
        int j=0;
        int n=s.length();
        int len=0;

        while(j<n){
            if(st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
            else{
            st.insert(s[j]);
            len=max(len,j-i+1);
            j++;
            }
        }
        return len;
    }
};