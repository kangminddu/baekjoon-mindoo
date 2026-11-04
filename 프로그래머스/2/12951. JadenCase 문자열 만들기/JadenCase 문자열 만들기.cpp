#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    for (char &c : s){
        if (c == ' '){
            answer.push_back(' ');
            index = 0;
        }
        else{
            if (index == 0){
                answer.push_back(toupper(c));
            }else{
                answer.push_back(tolower(c));
            }
            index++;
        }
    }
    return answer;
}