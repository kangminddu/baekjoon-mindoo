#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second 
int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    int mx = 0; // 그림의 최대값
    int num = 0; // 그림의 수
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == 0 || vis[i][j]) continue; // 해당 칸이 색칠이 안된 부분(0)이거나 이미 (i, j)를 방문햇을 경우 넘어감
            num++;
            queue<pair<int,int>> Q;
            vis[i][j] = 1;
            Q.push({i,j});
            int area = 0; // 그림의 넓이
            while(!Q.empty()){
                area++; // 큐에 들어있는 원소를 하나 뺄 때 마다 넓이를 1 증가
                pair<int, int> cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
                    if (vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닌 경우
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            mx = max(mx, area);
        }
    }
    cout << num << endl << mx;
    return 0;
}