#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

void dfs(int cur, int n, vector<vector<int>>& computers){
    visited[cur] = true;
    for (int next = 0; next < n; next++){
        if (computers[cur][next] == 1 && !visited[next]){
            dfs(next, n, computers);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    visited.assign(n, false);
    int answer = 0;
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}