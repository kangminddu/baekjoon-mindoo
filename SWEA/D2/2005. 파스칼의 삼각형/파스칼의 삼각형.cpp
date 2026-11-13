#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
        cin >> N;
        vector<vector<int>> p(N);
        for (int i = 0; i < N; i++){
            p[i].assign(i + 1, 1);
        	for (int j = 1; j < i; j++){
            	p[i][j] = p[i-1][j-1] + p[i-1][j];
            }
        }
        cout << "#" << test_case << "\n";
        for (int i = 0; i < N; i++){
        	for (int j = 0; j <= i; j++){
            	cout << p[i][j];
                if (j < i) cout << " ";
            }
            cout << "\n";
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}