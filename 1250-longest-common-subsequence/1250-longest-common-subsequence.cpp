class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                    else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
            }
            return dp[0][0];
        }
    };

//     int lcs(string text1, string text2, int i, int j, vector<vector<int>>& memo) {
//         if (i == text1.size() || j == text2.size()) {
//             return 0;
//         }
//         if (text1[i] == text2[j]) {
//             memo[i][j] = 1 + lcs(text1, text2, i + 1, j + 1, memo);
//         } else {
//             int includeText1 = lcs(text1, text2, i + 1, j, memo);
//             int includeText2 = lcs(text1, text2, i, j + 1, memo);
//             memo[i][j] = max(includeText1, includeText2);
//         }

//         return memo[i][j];
//     }
// }