#include<iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		vector<string> answer(5);
        for (int i = 0; i < 5; i++) cin >> answer[i];
        
        cout << "#" << test_case << " ";
        for (int j = 0; j < 15; j++){
        	for (int i = 0; i < 5; i++){
            	if (j < answer[i].size()) cout << answer[i][j];
            }
        }
        cout << "\n";
	}
	return 0;
}