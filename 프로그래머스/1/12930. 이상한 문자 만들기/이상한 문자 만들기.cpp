#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int count = 0;
    for (char &c : s){
        if (c == ' '){
            answer.push_back(' ');
            count = 0;
        }else{
            answer.push_back(count % 2 == 0 ? toupper(c) : tolower(c));
            count++;
        }
    }
    return answer;
}