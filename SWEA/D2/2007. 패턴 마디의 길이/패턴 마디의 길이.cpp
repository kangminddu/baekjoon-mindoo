#include<iostream>

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
        int index = 0;
        string answer = "";
        for (int i = 1; i < text.size(); i++){
            	if (text.substr(0,i) == text.substr(i + 1, i)){
                	answer = text.substr(0,i);
                    break;
                }  
        }
        cout << "#" << test_case << " " << answer.length() + 1<< "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}