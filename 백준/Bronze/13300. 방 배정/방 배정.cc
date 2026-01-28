#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> arr(2, vector<int>(7,0));

    for (int i = 0; i < N; i++){
        int s, y;
        cin >> s >> y;
        arr[s][y]++;
    }

    int total = 0;
    for (int s = 0; s < 2; s++){
        for (int y = 1; y <= 6; y++){
            int count = arr[s][y];
            if (count == 0) continue;

            total += count / K;

            if (count % K != 0){
                total++;
            }
        }
    }
    cout << total << endl;
    return 0;
}