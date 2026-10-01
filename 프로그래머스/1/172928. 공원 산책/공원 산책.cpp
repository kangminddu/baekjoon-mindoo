#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int h = park.size();
    int w = park[0].size();
    int r = 0, c = 0;
    
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (park[i][j] == 'S'){
                r = i;
                c = j;
            }
        }
    }
    
    for (const string& route : routes){
        char direction = route[0];
        int distance = stoi(route.substr(2));
        
        int dr = 0, dc = 0;
        if (direction == 'N') dr = -1;
        else if (direction == 'S') dr = 1;
        else if (direction == 'E') dc = 1;
        else if (direction == 'W') dc = -1;
        
        int nr = r, nc = c;
        bool possible = true;
        
        for (int step = 0; step < distance; step++){
            nr += dr;
            nc += dc;
            
            if (nr < 0 || nr >= h || nc < 0 || nc >= w){
                possible = false;
                break;
            }
            
            if (park[nr][nc] == 'X'){
                possible = false;
                break;
            }
        }
        
        if (possible){
            r = nr;
            c = nc;
        }
    }
    return {r, c};
}