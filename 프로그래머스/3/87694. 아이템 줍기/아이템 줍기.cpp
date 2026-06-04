#include <string>
#include <vector>
#include <queue>

using namespace std;

int board[102][102];
bool visited[102][102];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};



int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    for (auto r : rectangle){
        int x1 = r[0] * 2;
        int y1 = r[1] * 2;
        int x2 = r[2] * 2;
        int y2 = r[3] * 2;
        
        for (int x = x1; x <= x2; x++){
            for (int y = y1; y <= y2; y++){
                board[x][y] = 1;
            }
        }
    }
    
    for (auto r : rectangle){
        int x1 = r[0] * 2;
        int y1 = r[1] * 2;
        int x2 = r[2] * 2;
        int y2 = r[3] * 2;
        
        for (int x = x1 + 1; x < x2; x++){
            for (int y = y1 + 1; y < y2; y++){
                board[x][y] = 0;
            }
        }
    }
    
    queue<pair<pair<int,int>, int>> q;
    q.push({{characterX * 2, characterY * 2}, 0});
    visited[characterX * 2][characterY * 2] = true;
    
    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        
        q.pop();
        
        if (x == itemX * 2 && y == itemY * 2) return dist/2;
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= 102 || ny >= 102) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            q.push({{nx, ny}, dist + 1});
        }
        
    }
    
    return 0;
}