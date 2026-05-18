#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int> &money, int start, int end){
    int len = end - start + 1;
    if (len == 1) return money[start];
    
    vector<int> dp(len,0);
    dp[0] = money[start];
    dp[1] = max(money[start], money[start+1]);
    for (int i = 2; i < len; i++){
        dp[i] = max(dp[i-1], dp[i-2] + money[start + i]);
    }
    return dp[len-1];
}

int solution(vector<int> money) {
    int N = money.size();
    int caseA = rob(money, 0, N-2);
    int caseB = rob(money, 1, N-1);
    return max(caseA, caseB);
}