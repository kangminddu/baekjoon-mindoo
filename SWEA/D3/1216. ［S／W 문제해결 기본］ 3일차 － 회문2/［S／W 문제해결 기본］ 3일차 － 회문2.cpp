#include<iostream>
#include <vector>
#include <string>

using namespace std;
// s의 st번째부터 len글자가 회문인지 (복사 없이 위치로만 확인)
bool isPal(const string& s, int st, int len){
	int l = st, r = st + len - 1;
    while (l < r){
    	if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}
// 한 줄에서 best보다 긴 회문이 있으면 그 길이, 없으면 best 그대로
int longest(const string& s, int best){
	for (int len = s.size(); len > best; len--){
    	for (int st = 0; st + len <= s.size(); st++){
        	if (isPal(s, st, len)) return len;
        }
    }
    return best;
}

int main(int argc, char** argv)
{
	int test_case;
	
	for(test_case = 1; test_case <= 10; ++test_case)
	{
		int num;
        cin >> num;
        vector<string> rows(100);
        for (int i = 0; i < 100; i++) cin >> rows[i];
        
        vector<string> cols(100, "");
        for (int c = 0; c < 100; c++){
        	for (int r = 0; r < 100; r++){
            	cols[c] += rows[r][c];
            }
        }
        int best = 1;
        for (int i = 0; i < 100; i++){
        	best = longest(rows[i], best);
            best = longest(cols[i], best);
        }
        cout << "#" << num << " " << best << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}