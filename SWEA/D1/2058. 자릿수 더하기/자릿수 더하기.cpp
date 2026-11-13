
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int N;
    cin >> N;
    int sum = 0;
    if (N > 1000){
        sum = N / 1000 + (N % 1000) / 100 + (N % 100) / 10 + N % 10;
    }
    else if (N > 100){
    	sum = N / 100 + (N % 100) / 10 + N % 10;
    }else if (N > 10){
    	sum = N / 10 + N % 10;
    }else sum = N;
    cout << sum;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}