#include<iostream>
#include <vector>
using namespace std;

vector<vector<int>> rotate(const vector<vector<int>>& a, int N){
	vector<vector<int>> r(N, vector<int>(N));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            r[i][j] = a[N-1-j][i];
        }
    }
	return r;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
        cin >> N;
        vector<vector<int>> a(N, vector<int>(N));
        for (int i = 0; i < N; i++){
        	for (int j = 0; j < N; j++){
            	cin >> a[i][j];
            }
        }
        auto r90 = rotate(a, N);
        auto r180 = rotate(r90, N);
        auto r270 = rotate(r180, N);
        
        cout << "#" << test_case << "\n";
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++) cout << r90[i][j];
            cout << " ";
            for (int j = 0; j < N; j++) cout << r180[i][j];
            cout << " ";
            for (int j = 0; j < N; j++) cout << r270[i][j];
            cout << "\n";
        }
	}
	return 0;
}