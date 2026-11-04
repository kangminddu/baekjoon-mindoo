#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (auto ans : s){
        if (ans >= 'a' && ans <= 'z'){
            answer.push_back('a' + (ans - 'a' + n) % 26);
        }
        else if (ans >= 'A' && ans <= 'Z'){
            answer.push_back('A' + (ans - 'A' + n) % 26);
        }
        else {
            answer.push_back(ans);
        }
    }
    return answer;
}