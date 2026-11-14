#include<iostream>
#include <string>
#include <vector>
using namespace std;

bool isPal(const string& s){
	int l = 0, r = s.size() - 1;
    while ( l < r){
    	if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main(int argc, char** argv)
{
	int test_case;
	
	for(test_case = 1; test_case <= 10; ++test_case)
	{
		int N;
        cin >> N;
        vector<string> b(8);
        for (int i = 0; i < 8; i++) cin >> b[i];
        int cnt = 0;
        
        for (int r = 0; r < 8; r++){
        	for (int c = 0; c + N <= 8; c++){
            	if (isPal(b[r].substr(c, N))) cnt++;
            }
        }
        vector<string> cols(8, "");
        for (int c = 0; c < 8; c++){
        	for (int r = 0; r < 8; r++){
            	cols[c] += b[r][c];
            }
        }
        for (int c = 0; c < 8; c++){
        	for (int s = 0; s + N <= 8; s++){
            	if (isPal(cols[c].substr(s, N))) cnt++;
            }
        }
        cout << "#" << test_case << " " << cnt << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}