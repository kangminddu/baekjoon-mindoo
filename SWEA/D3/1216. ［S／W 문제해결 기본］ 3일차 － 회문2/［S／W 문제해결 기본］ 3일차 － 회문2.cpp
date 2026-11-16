#include<iostream>
#include <string>
#include <vector>
using namespace std;

bool isPal(const string& s, int st, int len){
	int l = st, r = st + len - 1;
    while (l < r){
    	if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

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
		int N;
        cin >> N;
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
        cout << "#" << N << " " << best << "\n";
	}
	return 0;
}