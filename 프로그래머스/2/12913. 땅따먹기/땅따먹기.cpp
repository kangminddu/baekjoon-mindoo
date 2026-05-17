#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int N = land.size();
    vector<vector<int>> dp(N, vector<int>(4,0));
    
    for (int j = 0; j < 4; j++) dp[0][j] = land[0][j];
    
    for (int i = 1; i < N; i++){
        for (int j = 0; j < 4; j++){
            int best = 0;
            for (int k = 0; k < 4; k++){
                if (k == j) continue;
                best = max(best, dp[i-1][k]);
            }
            dp[i][j] = land[i][j] + best;
        }
    }
    
    for (int j = 0; j < 4; j++){
        answer = max(answer, dp[N-1][j]);
    }

    return answer;
}