#include <iostream>
#include <vector>
#include <algorithm> // max 함수 사용

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    // 계단 점수 저장 (1번 인덱스부터 쓰기 위해 N+1 크기)
    vector<int> score(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> score[i];
    }

    // DP 테이블 (해당 계단까지의 최대 점수)
    vector<int> dp(N + 1);

    // [초기값 설정]
    dp[1] = score[1];
    
    // N이 1일 수도 있으므로 예외 처리 필요
    if (N >= 2) {
        dp[2] = score[1] + score[2];
    }

    // [점화식 적용]
    // 3번째 계단부터 끝까지 계산
    for (int i = 3; i <= N; i++) {
        // 경우 1: 두 계단 전에서 점프 (i-2 -> i)
        // 경우 2: 세 계단 전에서 점프 후 한 칸 걷기 (i-3 -> i-1 -> i)
        dp[i] = max(dp[i-2], dp[i-3] + score[i-1]) + score[i];
    }

    cout << dp[N] << "\n";

    return 0;
}