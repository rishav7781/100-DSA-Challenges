class Solution {
public:
    int t[10005];

    // function jisme idx se n-1 tak minimum jumps find krne h
    int solve(int idx, vector<int> &nums, int n){
        // agar last index ya usse aage pahunch gaye => 0 jumps aur chahiye hi nahi
        if(idx >= n-1) return 0;

        // memo
        if(t[idx] != -1) return t[idx];

        int ans = 1e9; // very large, taaki min properly mile

        // jitna nums[idx] jump de raha utne possible explore kro
        for(int jump = 1; jump <= nums[idx]; jump++){
            ans = min(ans, 1 + solve(idx + jump, nums, n));
        }

        return t[idx] = ans;
    }

    int jump(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int n = nums.size();
        return solve(0, nums, n);
    }
};
