#include<iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	string grades[10] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
        cin >> N >> K;
        vector<int> score(N);
        for (int i = 0; i < N; i++){
        	int mid, fin, hw;
            cin >> mid >> fin >> hw;
            score[i] = mid * 35 + fin * 45 + hw * 20;
        }
		int target = score[K-1];
        int rank = 0;
        for (int i = 0; i < N; i++){
        	if (score[i] > target) rank++;
        }
        int per = N / 10; // 학점 하나당 학생 수
        cout << "#" << test_case << " " << grades[rank / per] << "\n";
	}
	return 0;
}