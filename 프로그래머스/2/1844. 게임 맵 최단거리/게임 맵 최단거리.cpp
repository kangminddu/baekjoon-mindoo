#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps) {
    int N = maps.size();      // 행 개수
    int M = maps[0].size();   // 열 개수
    
    // dist[r][c] = (0,0)에서 (r,c)까지 최단 거리. -1은 미방문
    vector<vector<int>> dist(N, vector<int>(M, -1));
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    // BFS 시작
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;  // 시작 칸도 1로 카운트
    
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            
            // 경계 체크
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            // 벽 체크
            if (maps[nr][nc] == 0) continue;
            // 미방문 체크
            if (dist[nr][nc] != -1) continue;
            
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
    
    return dist[N-1][M-1];  // 도착 칸의 거리 (-1이면 못 감)
}