#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> cnt;
    for (const string& name : participant) cnt[name]++;
    for (const string&name : completion) cnt[name]--;
    
    for (const string& name : participant){
        if (cnt[name] > 0) return name;
    }
    return "";
}