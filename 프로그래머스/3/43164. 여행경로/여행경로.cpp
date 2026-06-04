#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[10001];
vector<string> answer;

bool dfs(string now, vector<vector<string>>& tickets,
        vector<string>& path,
        int count){
    if (count == tickets.size()){
        answer = path;
        return true;
    }
    
    for (int i = 0; i < tickets.size(); i++){
        string from = tickets[i][0];
        string to = tickets[i][1];
        
        if (!visited[i] && from == now){
            visited[i] = true;
            
            path.push_back(to);
            if (dfs(to, tickets, path, count + 1)) return true;
            visited[i] = false;
            path.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(), tickets.end());
    vector<string> path;
    path.push_back("ICN");
    dfs("ICN", tickets, path, 0);
    return answer;
}