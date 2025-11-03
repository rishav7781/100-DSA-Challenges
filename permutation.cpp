class Solution {
public:
    int n;
    unordered_set<int>st;
    vector<vector<int>> result;

    void solve(vector<int>& nums, vector<int>&temp){
        if(temp.size()>=n){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            //choose
            if(st.find(nums[i])==st.end()){
            temp.push_back(nums[i]);
            //mark
            st.insert(nums[i]);
            //explore
            solve(nums,temp); //like ek baar 1 le liya toh phle size check hoga temp ka then loop me phir ayega 0 me 
                            // 0 me toh 1 already h toh 1 me 2 ko choose karega then phir explore karega
            //unmark
            temp.pop_back(); //backtrack jab full hogya toh peeche se nikl lengye or set se v erase
            st.erase(nums[i]);     //phir 0 me 1 le kr kare the aab 1 me 2 le kr hoga
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        n=nums.size();

        solve(nums,temp);
        return result;
    }
};