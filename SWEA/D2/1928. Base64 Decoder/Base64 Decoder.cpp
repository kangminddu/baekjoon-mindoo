#include<iostream>
#include <string>
#include <bitset>
using namespace std;

int val(char c){
	if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
    if (c == '+') return 62;
    else return 63;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		string text;
        cin >> text; 
        string bits = "";
        for (char c : text){
        	bits += bitset<6>(val(c)).to_string();
        }
        string result = "";
        for (int i = 0; i + 8 <= bits.size(); i += 8){
			result += (char)bitset<8>(bits.substr(i,8)).to_ulong();    	
        }
        cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}