#include <iostream>
#include <stack>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    // 키, 같은 키를 가진 사람의 수
    stack<pair<int, int>> s;
    long long ans = 0;

    for (int i = 0; i < N; i++){
        int height;
        cin >> height;

        // 키, 연속된 같은 키 개수
        pair<int,int> cur = {height, 1};

        while (!s.empty() && s.top().first <= height){
            ans += s.top().second;

            if (s.top().first == height){
                cur.second += s.top().second;
            }
            s.pop();
        }
        // 스택에 아직 사람이 남아있다면 나보다 키 큰 사람이 존재한다는 것
        if (!s.empty()){
            ans++;
        }
        // 나를 스택에 추가
        s.push(cur);
    }
    cout << ans << endl;

    return 0;
}