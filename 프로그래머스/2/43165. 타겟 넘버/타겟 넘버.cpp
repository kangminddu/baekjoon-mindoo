#include <vector>
using namespace std;

int dfs(const vector<int>& numbers, int target, int index, int sum) {
    if (index == numbers.size()) {
        return sum == target ? 1 : 0;
    }

    return dfs(numbers, target, index + 1, sum + numbers[index])
         + dfs(numbers, target, index + 1, sum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}