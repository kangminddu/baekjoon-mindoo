#include<iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int H, W;
        cin >> H >> W;
        vector<string> map(H);
        for (int i = 0; i < H; i++) cin >> map[i];
        int num;
		string command;
        cin >> num >> command;
        
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        string shape = "^v<>";
        string keys = "UDLR";
        int r = 0, c = 0, dir = 0;
        for (int i = 0; i < H; i++){
        	for (int j = 0; j < W; j++){
            	size_t k = shape.find(map[i][j]);
                if (k != string::npos){
                	r = i;
                    c = j;
                    dir = k;
                }
            }
        }
        for (char ch : command){
        	if (ch == 'S'){
            	int nr = r + dr[dir], nc = c + dc[dir];
                while (nr >= 0 && nr < H && nc >= 0 && nc < W){
                	if (map[nr][nc] == '*'){
                    	map[nr][nc] = '.';
                        break;
                    }
                    if (map[nr][nc] == '#') break;
                    nr += dr[dir];
                    nc += dc[dir];
                }
            }else{
            	dir = keys.find(ch);
                map[r][c] = shape[dir];
                int nr = r + dr[dir], nc = c + dc[dir];
                if (nr >= 0 && nr < H && nc >= 0 && nc < W && map[nr][nc] == '.'){
                	map[r][c] = '.';
                    r = nr;
                    c = nc;
                    map[r][c] = shape[dir];
                }
            }
        }
        cout << "#" << test_case << " ";
        for (int i =0; i < H; i++) cout << map[i] << "\n";
	}
	return 0;
}