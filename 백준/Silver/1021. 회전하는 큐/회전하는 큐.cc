#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    deque<int> dq;
    for (int i = 1; i <= N; i++){
        dq.push_back(i);
    }

    int count = 0;

    for (int i = 0; i < M; i++){
        int target;
        cin >> target;
        
        int index = 0;
        for (int j = 0; j < dq.size(); j++){
            if (dq[j] == target){
                index = j;
                break;
            }

        }

        if (index <= dq.size() / 2){
            while (dq.front() != target){
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
            }
        }
        else{
            while (dq.front() != target){
                dq.push_front(dq.back());
                dq.pop_back();
                count++;
            }
        }
        dq.pop_front();
    }
    cout << count << endl;

    return 0;
}