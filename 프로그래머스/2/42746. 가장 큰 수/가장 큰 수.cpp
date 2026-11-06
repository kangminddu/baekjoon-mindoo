#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strs;
    for (int n : numbers) strs.push_back(to_string(n));
    sort(strs.begin(), strs.end(), cmp);
    
    if (strs[0] == "0") return "0";
    
    for (const string& s : strs) answer += s;
    return answer;
}