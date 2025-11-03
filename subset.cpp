class Solution {
public:
    vector<vector<int>> result;
    int n;
    void solve(vector<int> & nums, int idx , vector<int>& temp){
        if(idx>=n){
            result.push_back(temp);
            return;
        }
        //take
        temp.push_back(nums[idx]);
        solve(nums,idx+1,temp);
        //not take
        temp.pop_back();
        solve(nums,idx+1,temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<int>temp;
        solve(nums,0,temp);

        return result;
    }
};