#include<iostream>
#include <vector>
using namespace std;

int N, answer;
vector<bool> col, d1,d2;

void dfs(int row){
	if (row == N){
       	answer++;
        return;
    }
   	for (int c = 0; c < N; c++){
    	if (col[c] || d1[row + c] || d2[row -c + N -1]) continue;
        col[c] = d1[row + c] = d2[row-c+N-1] = true;
        dfs(row + 1);
        col[c] = d1[row+c] = d2[row-c+N-1] = false;
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
		cin >> N;
        answer = 0;
		col.assign(N,0);
        d1.assign(2 * N -1, 0);
        d2.assign(2 * N - 1, 0);
        dfs(0);
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}