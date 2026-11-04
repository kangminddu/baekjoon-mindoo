#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();                          // 압축 안 했을 때가 기본값

    for (int k = 1; k <= s.size() / 2; k++) {       // 자르는 단위
        string result = "";
        string prev = s.substr(0, k);               // 첫 조각
        int count = 1;

        for (int i = k; i < s.size(); i += k) {
            string cur = s.substr(i, k);            // 다음 조각
            if (cur == prev) {
                count++;                            // 같으면 개수만 증가
            } else {
                if (count > 1) result += to_string(count);
                result += prev;                     // 다르면 지금까지 기록
                prev = cur;
                count = 1;
            }
        }
        // ⚠️ 마지막 묶음 기록 (빼먹기 쉬움!)
        if (count > 1) result += to_string(count);
        result += prev;

        answer = min(answer, (int)result.size());
    }
    return answer;
}