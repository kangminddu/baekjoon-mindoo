#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;
vector<string> path;
vector<bool> used;

bool dfs(const vector<vector<string>>& tickets, const string& cur){
    if (path.size() == tickets.size() + 1){
        answer = path;
        return true;
    }
    for (int i = 0; i < tickets.size(); i++){
        if (used[i] || tickets[i][0] != cur) continue;
        used[i] = true;
        path.push_back(tickets[i][1]);
        if (dfs(tickets, tickets[i][1])) return true;
        used[i] = false;
        path.pop_back();
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    used.assign(tickets.size(), false);
    path.push_back("ICN");
    dfs(tickets, "ICN");
    return answer;
}