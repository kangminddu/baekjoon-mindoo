#include <iostream>
#include <stack>



using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    stack<int> s;
    long long count = 0;
    for (int i = 0; i < N; i++){
        long long height;
        cin >> height;

        while (!s.empty() && s.top() <= height){
            s.pop();
        }
        count += s.size();

        s.push(height);
    }

    cout << count << endl;
    return 0;
}