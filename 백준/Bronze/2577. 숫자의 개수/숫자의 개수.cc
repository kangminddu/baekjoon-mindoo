#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    vector<int> arr(10,0);

    int abc = A * B * C;
    string ABC = to_string(abc);
    
    for (int i = 0; i < ABC.length(); i++){
        arr[ABC[i] - '0']++;
    }

    for (int i = 0; i < 10; i++){
        cout << arr[i] << endl;
    }
    return 0;
}