#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows, vector<int>(columns));
    
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < columns; c++){
            board[r][c] = r * columns + c + 1;
        }
    }
   
    
    for (const auto& q : queries){
        int r1 = q[0] - 1;
        int r2 = q[2] - 1;
        int c1 = q[1] - 1;
        int c2 = q[3] - 1;
        vector<pair<int,int>> edge;
        for (int c = c1; c <= c2; c++) edge.push_back({r1, c}); // 위쪽
        for (int r = r1 + 1; r <= r2; r++) edge.push_back({r, c2}); // 오른쪽
        for (int c = c2 - 1; c >= c1; c--) edge.push_back({r2, c}); // 아래쪽
        for (int r = r2 - 1; r > r1; r--) edge.push_back({r, c1}); // 왼쪽
        
        vector<int> values;
        int smallest = rows * columns + 1;
        
        for (const auto& cell : edge){
            int value = board[cell.first][cell.second];
            values.push_back(value);
            smallest = min(smallest, value);
        }
        
        int n = edge.size();
        for (int i = 0; i < n ; i++){
            int next = (i + 1) % n;
            board[edge[next].first][edge[next].second] = values[i];
        }
        answer.push_back(smallest);
    }
    return answer;
}