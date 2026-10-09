#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int changeDays(string date){
    int year = stoi(date.substr(0,4));
    int month = stoi(date.substr(5,2));
    int day = stoi(date.substr(8,2));
    
    return (year * 12 * 28) + (month * 28) + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int stoday = changeDays(today);
    
    unordered_map<char, int> typeday;
    
    for (const string& term : terms){
        char type = term[0];
        int durationDay = stoi(term.substr(2)) * 28;
        
        typeday[type] = durationDay;
    }
    
    for (int i = 0; i < privacies.size(); i++){
        string strcurday = privacies[i].substr(0,10);
        char type = privacies[i][11];
        int curday = changeDays(strcurday);
        int expireDate = curday + typeday[type];
        
        if (stoday >= expireDate){
            answer.push_back(i + 1);
        }
    }
    return answer;
}