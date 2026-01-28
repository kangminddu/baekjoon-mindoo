#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

    vector<int> arr(26,0);

    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++){
        arr[input[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++){
        cout << arr[i] << ' ';
    }
    return 0;
}