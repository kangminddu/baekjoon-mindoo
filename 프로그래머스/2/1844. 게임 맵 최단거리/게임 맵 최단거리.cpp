#include<vector>
#include <queue>

using namespace std;



int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    
    vector<vector<int>> dist(n, vector<int>(m,0));
    queue<pair<int, int>> q;
    q.push({0,0});
    dist[0][0] = 1;
    
    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (maps[nr][nc] == 0 || dist[nr][nc] != 0) continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr,nc});
        }
    }
    return dist[n-1][m-1] == 0 ? -1: dist[n-1][m-1];
}