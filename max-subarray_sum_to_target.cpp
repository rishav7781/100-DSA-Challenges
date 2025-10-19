class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp; //{cumSum, freq}

        mp[0]=1;
        int cnt=0;
        int cumSum=0;

        for(int &n : nums){
            cumSum+=n;
            if(mp.find(cumSum-k)!=mp.end()){
                cnt+=mp[cumSum-k];
            }
            mp[cumSum]++;
        }

        return cnt;
    }
};