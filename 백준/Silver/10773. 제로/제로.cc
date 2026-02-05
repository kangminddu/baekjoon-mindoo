#include <iostream>
#include <stack>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K;
    cin >> K;
    int input;
    stack<int> s;
    for (int i = 0; i < K; i++){
        cin >> input;
        if (input == 0){
            s.pop();
        }
        else{
            s.push(input);
        }

        
    }
    int total = 0;
    while (!s.empty()){
        total += s.top();
        s.pop();
    }
    cout << total << endl;
    

    return 0;
}