#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    stack<int> s;
    string result = "";
    int cnt = 1;
    for (int i = 0; i < n; i++){
        int input;
        cin >> input;

        while (cnt <= input){
            s.push(cnt);
            cnt++;
            result += "+\n";
        }
        if (s.top() == input){
            s.pop();
            result += "-\n";
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    cout << result;

    return 0;
}