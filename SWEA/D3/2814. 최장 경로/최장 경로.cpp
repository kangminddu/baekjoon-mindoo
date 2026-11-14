#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, best;
vector<vector<int>> g;
vector<bool> visited;

void dfs(int v, int len){
	best = max(best, len);
    for (int u = 1; u <= N; u++){
    	if (g[v][u] == 1 && !visited[u]){
        	visited[u] = true;
            dfs(u, len + 1);
            visited[u] = false;
        }
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> M;
		g.assign(N + 1, vector<int>(N + 1, 0));
        visited.assign(N + 1, false);
        for (int i = 0; i < M; i++){
        	int x, y;
            cin >> x >> y;
            g[x][y] = g[y][x] = 1; // 무방향이라
        }
        best = 0;
        for (int s = 1; s  <= N; s++){
        	visited[s] = true;
            dfs(s, 1);
            visited[s] = false;
        }
        cout << "#" << test_case << " " << best << "\n";
	}
	return 0;
}