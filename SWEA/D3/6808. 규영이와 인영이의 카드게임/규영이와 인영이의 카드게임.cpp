#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int gyu[9], in[9];
        bool has[19] = {false};
        for (int i = 0; i < 9; i++){
        	cin >> gyu[i];
            has[gyu[i]] = true;
        }
        int k = 0;
        for (int c = 1; c <= 18; c++){
        	if (!has[c]) in[k++] = c;
        }
		int win = 0, lose = 0;
        do {
        	int g = 0, y = 0;
            for (int i = 0; i < 9; i++){
            	if (gyu[i] > in[i]) g += gyu[i] + in[i];
                else y += gyu[i] + in[i];
            }
            if (g > y) win++;
            else if (g < y) lose++;
        }while (next_permutation(in, in + 9));
        cout << "#" << test_case << " " << win << " " << lose << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}