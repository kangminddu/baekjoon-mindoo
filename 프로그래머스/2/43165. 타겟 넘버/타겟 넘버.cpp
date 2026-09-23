#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& numbers, int target, int index, int count){
    if (index == numbers.size()){
        return count == target ? 1 : 0;
    }
    return dfs(numbers, target, index + 1, count + numbers[index]) +
        dfs(numbers, target, index + 1, count - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}