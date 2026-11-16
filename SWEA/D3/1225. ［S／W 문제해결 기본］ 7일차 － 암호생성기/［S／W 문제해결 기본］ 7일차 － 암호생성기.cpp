#include<iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	for(test_case = 1; test_case <= 10; ++test_case)
	{
		int num;
        cin >> num;
        
        queue<int> q;
        for (int i = 0; i < 8; i++){
        	int v;
            cin >> v;
            q.push(v);
        }
        bool done = false;
        while (!done){
        	for (int d = 1; d <= 5; d++){
            	int x = q.front() - d;
                q.pop();
                if (x <= 0){
                	q.push(0);
                    done = true;
                    break;
                }
                q.push(x);
            }
        }
        cout << "#" << num;
        for (int i = 0; i < 8; i++){
        	cout << " " << q.front();
            q.pop();
        }
        cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}