#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for (char c : s){
        int moved = 0;
        while (moved < index){
            c = 'a' + (c - 'a' + 1) % 26;
            if (skip.find(c) == string::npos){
                moved++;
            }
        }
        answer.push_back(c);
    }
    return answer;
}