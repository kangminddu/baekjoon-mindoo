#include <string>
#include <vector>
using namespace std;
const int MOD = 1000000007;
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    vector<vector<bool>> isPuddle(n+1, vector<bool>(m+1, false));
    
    for (auto& p : puddles){
        int col = p[0], row = p[1];
        isPuddle[row][col] = true;
    }
    dp[1][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j<= m; j++){
            if (isPuddle[i][j]) dp[i][j] = 0;
            else{
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    answer = dp[n][m];
    return answer;
}