#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> cnt;
    for (const auto& c : clothes) cnt[c[1]]++;
    
    for (const auto& p : cnt) answer *= (p.second + 1);
    return answer - 1;
}