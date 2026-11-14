
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int A, B;
    cin >> A >> B;
    if (A == 3 && B == 2) cout << "A" << "\n";
	else if (A == 3 && B == 1) cout << "B" << "\n";
    else if (A == 2 && B == 1) cout << "A" << "\n";
    else if (A == 2 && B == 3) cout << "B" << "\n";
    else if (A == 1 && B == 3) cout << "A" << "\n";
    else cout << "B" << "\n";
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}