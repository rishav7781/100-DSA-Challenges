class Solution {
public:
    int n;
    int t[10001];
    bool solve(int idx, vector<int>&nums){
        if(idx==n-1) return true;
        if(idx>=n) return true;
        if(t[idx]!=-1) return t[idx];
        for(int jump=1;jump<=nums[idx];jump++){
            if(solve(jump+idx,nums)) return t[idx]=1;
        }

        return t[idx]=0;
    }
    bool canJump(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        //logic simple sa h Abhi tak maximum kitna door tak pahunch sakta hoon Iska naam hai maxReachable.
        //i > maxReachable Matlab hum wahaan pahunch hi nahi sakte.
        // like if in [3,2,1,0,4] hear max reachble till index 3 is 3 so at index 3 max reachable is 3 i.e i<maxreach

        int maxReachable=0;
        for(int i=0;i<n;i++){
            if(i>maxReachable) return false;

            maxReachable=max(maxReachable, nums[i]+i);
        }
        return true;

    }
};