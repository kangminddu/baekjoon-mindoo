#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int N = triangle.size();
    vector<vector<int>> dp(N);
    for (int i = 0; i < N; i++) dp[i].resize(i + 1, 0);
    dp[0][0] = triangle[0][0];
    
    for (int i = 1; i < N; i++){
        for (int j = 0; j <= i; j++){
            int left = (j > 0) ? dp[i-1][j-1] : 0;
            int right = (j < i) ? dp[i-1][j] : 0;
            dp[i][j] = triangle[i][j] + max(left,right);
        }
    }
    for (int j = 0; j < N; j++){
        answer = max(answer, dp[N-1][j]);
    }
    return answer;
}