#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int n = maps.size(); // 행 개수
    int m = maps[0].size(); // 열 개수
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    vector<vector<int>> dist(n, vector<int>(m,-1)); // 전부 -1로 시작
    queue<pair<int,int>> q;
    dist[0][0] = 1; // 출발 칸은 1번째 칸
    q.push({0,0});
    
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int d = 0; d < 4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 맵 밖
            if (maps[nx][ny] == 0) continue; // 벽
            if (dist[nx][ny] != -1) continue; // 이미 감
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx,ny});
        }
    }
    return dist[n-1][m-1];
}