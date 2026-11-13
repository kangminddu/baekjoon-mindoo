#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		string text;
        cin >> text;
        string temp = text;
        bool correct = true;
        reverse(text.begin(), text.end());
        if (temp == text) correct = true;
        else correct = false;

        if (correct) cout << "#" << test_case << " " << "1" << "\n";
        else cout << "#" << test_case << " " << "0" << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}