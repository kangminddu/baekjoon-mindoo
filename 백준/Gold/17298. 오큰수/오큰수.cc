#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);

    vector<int> ans(N, -1);

    stack<int> s;

    for (int i = 0; i < N; i++){
        cin >> A[i];

        while (!s.empty() && A[s.top()] < A[i]){
            ans[s.top()] = A[i];
            s.pop();
        }
        s.push(i);

    }
    for (int i = 0; i < N; i++){
        cout << ans[i] << " ";
    }

    return 0;
}