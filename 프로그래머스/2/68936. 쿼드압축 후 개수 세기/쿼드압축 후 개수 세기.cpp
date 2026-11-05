#include <string>
#include <vector>

using namespace std;

void quad(vector<vector<int>>& arr, int x, int y, int size, vector<int>& answer){
    int first = arr[x][y];
    bool same = true;
    for (int i = x; i < x + size && same; i++){
        for (int j = y; j < y + size && same; j++){
            if (arr[i][j] != first){
                same = false;
                break;
            }
        }
    }
    
    if (same){
        answer[first]++;
        return;
    }
    
    int half = size / 2;
    quad(arr, x, y, half, answer);
    quad(arr, x, y + half, half, answer);
    quad(arr, x + half, y, half, answer);
    quad(arr, x + half, y+half, half, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    quad(arr, 0, 0, arr.size(), answer);
    return answer;
}