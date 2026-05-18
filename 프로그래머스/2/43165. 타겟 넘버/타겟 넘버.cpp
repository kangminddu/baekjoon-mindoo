#include <string>
#include <vector>
using namespace std;

void dfs(vector<int>& numbers, int target, int idx, int sum, int& count) {
    // 종료 조건: 모든 숫자를 다 봤음
    if (idx == numbers.size()) {
        if (sum == target) count++;
        return;
    }
    
    // 현재 숫자를 +로 선택
    dfs(numbers, target, idx + 1, sum + numbers[idx], count);
    // 현재 숫자를 -로 선택
    dfs(numbers, target, idx + 1, sum - numbers[idx], count);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}