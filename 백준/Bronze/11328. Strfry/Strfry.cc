#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int p;
    cin >> p;
    for (int i = 0; i < p; i++){
        string s1, s2;
        cin >> s1 >> s2;

        int count[26] = {0,};
        bool isPossible = true;

        for (int j = 0; j < s1.length(); j++){
            count[s1[j] - 'a']++;

        }

        for (int k = 0; k < s2.length(); k++){
            count[s2[k] - 'a']--;
        }

        for (int l = 0; l < 26; l++){
            if (count[l] != 0){
                isPossible = false;
                break;
            }
        }
        if (isPossible) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }

    return 0;
}