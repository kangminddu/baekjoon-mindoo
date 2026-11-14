#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        vector<vector<int>> board(100, vector<int>(100, 0));
        vector<int> sum_arr(100, 0);
        vector<int> sum_arrc(100, 0);
		int N;
        cin >> N;
        for (int i = 0; i < 100; i++){
        	for (int j = 0; j < 100; j++){
            	cin >> board[i][j];
            }
        }
        // 행의 덧셈 저장
        for (int i = 0; i < 100; i++){
            int sum = 0;
        	for (int j = 0; j < 100; j++){
            	sum += board[i][j];
                sum_arr[i] = sum;
            }
        }
        int best = 0;
        for (int i = 0; i <100; i++){
        	if (best < sum_arr[i]) best = sum_arr[i];
        }
        for (int j = 0; j < 100; j++){
        	int sum = 0;
            for (int i = 0; i < 100; i++){
            	sum += board[i][j];
                sum_arrc[j] = sum;
            }
        }
        for (int i = 0; i < 100; i++){
        	if (best < sum_arrc[i]) best = sum_arrc[i];
        }
        int best1 = 0;
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < 100; i++){
            sum1 += board[i][i];
            sum2 += board[i][99-i];
            best1 = max(sum1, sum2);
        }
        
        cout << "#" << test_case << " " << max(best, best1) << "\n";
	}
	return 0;
}