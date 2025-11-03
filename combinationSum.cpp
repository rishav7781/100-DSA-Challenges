class Solution {
public:
    int n;
    vector<vector<int>> result;
    set<vector<int>>st;

    void solve(vector<int>& candidates, int target, int i, vector<int> & temp){
        if(i>=n || target < 0) return;
        if(target ==0){
            if(st.find(temp)==st.end()){ //ni mila
                 result.push_back(temp);
                 st.insert(temp);
            }

           return;
        }
        temp.push_back(candidates[i]);

        //le kr aage chal gya
        solve(candidates,target-candidates[i],i+1,temp);

        //le kr wapas wahi lena chahte hai
        solve(candidates,target-candidates[i],i,temp);

        //nhi liya aage chla gya
        temp.pop_back();
        solve(candidates,target,i+1,temp);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int>temp;
        solve(candidates,target,0,temp);
        return result;
    }
};