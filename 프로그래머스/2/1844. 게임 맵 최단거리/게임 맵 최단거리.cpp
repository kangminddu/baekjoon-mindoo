#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, 0));
    
    dist[0][0] = 1;
    q.push({0, 0});
    
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        // 목적지에 도달한 경우 즉시 거리 반환 (선택 사항이지만 효율적)
        if (r == n - 1 && c == m - 1) {
            return dist[r][c];
        }
        
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            
            // 범위를 벗어나는지 확인
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            
            // 벽(0)이거나 이미 방문한 칸(dist > 0)인 경우 무시
            if (maps[nr][nc] == 0 || dist[nr][nc] > 0) continue;
            
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
    
    // 상대 팀 진영에 도착할 수 없는 경우
    return dist[n - 1][m - 1] == 0 ? -1 : dist[n - 1][m - 1];
}
