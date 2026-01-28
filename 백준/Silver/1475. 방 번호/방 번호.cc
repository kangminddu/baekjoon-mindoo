#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    int N;
    cin >> N;

    int count[10] = {0, };
    string n = to_string(N);

    for (int i = 0; i < n.length(); i++){
        count[n[i] - '0']++;
    }
    int six_nine_sum = count[6] + count[9];
    count[6] = (six_nine_sum + 1) / 2;
    count[9] = 0;

    int answer = 0;
    for (int i = 0; i < 10; i++){
        if (count[i] > answer){
            answer = count[i];
        }
    }
    cout << answer << endl;
    return 0;
}