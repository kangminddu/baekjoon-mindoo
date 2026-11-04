#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string new_id) {
    for (char &c : new_id){
        c = tolower(c);  
    }
    
    string s = "";
    for (char c : new_id){
        if (islower(c) || isdigit(c) || c == '-' || c == '_' || c == '.'){
            s += c;
        }
    }
    
    string t = "";
    for (char c : s){
        if (c == '.' && !t.empty() && t.back() == '.') continue;
        t += c;
    }
    
    if (!t.empty() && t.front() == '.') t.erase(0, 1);
    if (!t.empty() && t.back() == '.') t.pop_back();
    
    if (t.empty()) t = "a";
    
    if (t.size() >= 16){
        t = t.substr(0,15);
        if (t.back() == '.') t.pop_back();
    }
    
    while (t.size() <= 2) t += t.back();
    return t;
}