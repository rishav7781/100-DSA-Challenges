class Solution {
public:
     int t[100][100];
    int solve(int i, int j, int m, int n) {
        if(i<0|| j<0|| i >= m || j >= n) return 0;  // Out of bounds
        if(i == m-1 && j == n-1) return 1;  // Reached destination
         if(t[i][j] != -1) return t[i][j];
        int down = solve(i+1, j, m, n);
        int right = solve(i, j+1, m, n);
        return t[i][j]= down + right;
    }

    int uniquePaths(int m, int n) {
         memset(t,-1,sizeof(t));
        return solve(0, 0, m, n);  // Start from top-left
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // base case
        dp[m-1][n-1] = 1;

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) continue;  // already base case
                int down = 0, right = 0;
                if (i + 1 < m) down = dp[i + 1][j];
                if (j + 1 < n) right = dp[i][j + 1];
                dp[i][j] = down + right;
            }
        }
        return dp[0][0];
    }
};
