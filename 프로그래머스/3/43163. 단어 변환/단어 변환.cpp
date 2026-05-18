#include <string>
#include <vector>
#include <queue>

using namespace std;
bool oneDiff(string a, string b){
    int diff = 0;
    for (int i = 0; i < a.size(); i++){
        if (a[i] != b[i]) diff++;
    }
    return diff == 1;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> q;
    int N = words.size();
    bool found = false;
    for (int i = 0; i < N; i++){
        if (words[i] == target) {found = true; break;}
    }
    if (!found) return 0;
    vector<bool> visited(N, false);
    q.push({begin, 0});
    while (!q.empty()){
        auto [cur,step] = q.front();
        q.pop();
        if (cur == target) return step;
        for (int i = 0; i < N; i++){
            if (!visited[i] && oneDiff(cur, words[i])){
                visited[i] = true;
                q.push({words[i], step + 1});
            }
        }
    }
    return 0;
}