#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    string s = "";
    while (n > 0){
        s += '0' + n % 3;
        n /= 3;
    }
    
    int answer = 0;
    for (char c : s){
        answer = answer * 3 + (c - '0');
    }
    return answer;
}