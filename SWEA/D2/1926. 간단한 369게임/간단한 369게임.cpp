#include<iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{	
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++){
    	string s = to_string(i);
        int cnt = 0;
        for (char c : s){
        	if (c == '3' || c == '6' || c == '9') cnt++;
        }
        if (cnt == 0) cout << i;
        else cout << string(cnt, '-');
        cout << " ";
    }
    
	return 0;
}