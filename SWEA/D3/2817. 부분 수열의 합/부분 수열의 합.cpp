#include<iostream>
#include <vector>
using namespace std;
int N, K, cnt;
vector<int> a;

void dfs(int idx, int sum){
	if (sum > K) return;
    if (idx == N){
    	if (sum == K) cnt++;
        return;
    }
    dfs(idx + 1, sum + a[idx]);
    dfs(idx + 1, sum);
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> K;
        a.assign(N, 0);
        for (int i = 0; i < N; i++){
        	cin >> a[i];
        }
        cnt = 0;
        dfs(0, 0);
        cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}