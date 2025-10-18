class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());

        return st.size() < nums.size() ? false : true;
    }
};

//another way by sorting use nums[i]==nums[i+1] to check duplicates