#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int N;
    cin >> N;
    vector<int> num(N + 1);
    for (int i = 0; i <= N; i++){
    	num[i] = i;
    }
    sort(num.rbegin(), num.rend());
    for (int i = 0; i <= N; i++){
    	cout << num[i] << " ";
    }
    cout <<"\n";
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}