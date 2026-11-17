#include<iostream>
#include <stack>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	
	for(test_case = 1; test_case <= 10; ++test_case)
	{
		int N;
        string text;
        cin >> N >> text;
        
        string st = "";
        for (char c : text){
        	if (!st.empty() && st.back() == c){
            	st.pop_back();
            }else{
            	st.push_back(c);
            }
        }
        cout << "#" << test_case << " " << st << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}