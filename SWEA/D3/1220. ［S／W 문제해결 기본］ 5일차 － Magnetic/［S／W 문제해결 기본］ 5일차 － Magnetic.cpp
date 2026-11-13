#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
        cin >> N;
        vector<vector<int>> arr(N, vector<int>(N));
        for (int i = 0; i < N; i++){
        	for (int j = 0; j < N; j++){
            	cin >> arr[i][j];
            }
        }
        int count = 0;
        for (int c = 0; c < N; c++){
        	int last = 0;
            for (int r = 0; r < N; r++){
            	if (arr[r][c] == 0) continue;
                if (arr[r][c] == 2 && last == 1) count++;
                last = arr[r][c];
            }
        }
        cout << "#" << test_case << " " << count << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}