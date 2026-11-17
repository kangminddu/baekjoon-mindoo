#include<iostream>
#include <string>
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
        
        string doc = "";
        for (int i = 0; i < N; i++){
        	char c;
            int k ;
            cin >> c >> k;
            doc += string(k,c);
        }
        cout << "#" << test_case << "\n";
        for (int i = 0; i < doc.size(); i++){
        	cout << doc[i];
            if (i % 10 == 9) cout << "\n";
        }
        if (doc.size() % 10 != 0) cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}