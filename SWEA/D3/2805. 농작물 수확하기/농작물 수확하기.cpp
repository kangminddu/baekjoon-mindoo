#include<iostream>
#include <vector>
#include <string>
#include <cstdlib>
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
        int mid = N / 2;
        int sum = 0;
        
        for (int i = 0; i < N; i++){
        	string row;
            cin >> row;
            int k = mid - abs(i-mid);
            for (int j = mid - k; j <= mid + k; j++){
            	sum += row[j] - '0';
            }
        }
        cout << "#" << test_case << " " << sum << "\n";
	}
	return 0;
}