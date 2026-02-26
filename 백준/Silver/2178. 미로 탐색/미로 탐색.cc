#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n,m;
int dist[102][102];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x, y});

    while (!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] == 0) continue;
            
            if (dist[nx][ny] == 1){
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
    return dist[n-1][m-1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        string line;
        cin >> line;
        for (int j = 0; j < m; j++){
            dist[i][j] = line[j] - '0';
        }
    }
    cout << bfs(0,0) << endl;
}