#include<iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
        cin >> N >> M;
        vector<int> arr_a(N);
        vector<int> arr_b(M);
        for (int i = 0; i < N; i++) cin >> arr_a[i];
        for (int i = 0; i < M; i++) cin >> arr_b[i];
        int repeat = abs(N - M) + 1;
        int best = INT_MIN;
        if (N > M){
        	swap(arr_a,arr_b);
            swap(N,M);
        }
        for (int pos = 0; pos < repeat; pos++){
        	int sum = 0;
            for (int j = 0; j < N; j++){
            	sum += arr_a[j] * arr_b[pos + j];
            }
            best = max(best, sum);
        }
        cout << "#" << test_case << " " << best << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}