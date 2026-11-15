#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, M, K;
        cin >> N >> M >> K;
        vector<int> t(N);
        for (int i = 0; i < N; i++) cin >> t[i];
        sort(t.begin(), t.end()); // 도착 시각 순서로 정렬
        
        bool ok = true;
        for (int i = 0; i < N; i++){
        	int made = (t[i] / M) * K;
            if (made < i + 1){
            	ok = false;
                break;
            }
        }
        cout << "#" << test_case << " " << (ok ? "Possible" : "Impossible") << "\n";
	}
	return 0;
}