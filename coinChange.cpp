class Solution {
public:

    int solve(vector<int>& coins, int amount,int idx,vector<vector<int>> &dp){
        if(idx==0){
            if(amount % coins[0]==0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        int not_take= solve(coins,amount,idx-1,dp);
        int take=1e9;
        if(coins[idx]<=amount){
            take=1+solve(coins,amount-coins[idx],idx,dp);
        }

        return dp[idx][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= solve(coins,amount,n-1,dp);
        return (ans>=1e9) ? -1 : ans;
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        // Base case
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) dp[0][t] = t / coins[0];
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                int not_take = dp[i - 1][t];
                int take = 1e9;
                if (coins[i] <= t)
                    take = 1 + dp[i][t - coins[i]];
                dp[i][t] = min(take, not_take);
            }
        }

        int ans = dp[n - 1][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};
