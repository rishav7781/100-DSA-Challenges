// class Solution {
// public:
// int m;
//     int n;
//     int t[1001][1001];

//     int solve(string s1, string s2, int i, int j){
//         if(i>=m || j>=n) return 0;

//         if(t[i][j] != -1) return t[i][j];

//         if(s1[i] == s2[j]){
//             t[i][j] = 1 + solve(s1, s2, i+1, j+1);
//         } else {
//             int skipText1 = solve(s1, s2, i+1, j);
//             int skipText2 = solve(s1, s2, i, j+1);
//             t[i][j] = max(skipText1, skipText2);
//         }

//         return t[i][j];
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         m = text1.size();
//         n = text2.size();
//         memset(t, -1, sizeof(t));
//         return solve(text1, text2, 0, 0);
//     }
// };

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};