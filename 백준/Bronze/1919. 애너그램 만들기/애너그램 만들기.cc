#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int count1[26] = {0, };
    int count2[26] = {0, };

    for (int i = 0; i < s1.length(); i++){
        count1[s1[i] - 'a']++;
    }

    for (int j = 0; j < s2.length(); j++){
        count2[s2[j] - 'a']++;
    }

    int answer = 0;

    for (int k = 0; k < 26; k++){
        if (count1[k] > count2[k]){
            answer += count1[k] - count2[k];
        }
        else{
            answer += count2[k] - count1[k];
        }
    }
    cout << answer << endl;


    return 0;
}