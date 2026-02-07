#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    long long B;
    cin >> N >> M >> B;

    int map[500][500];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    int min = INT_MAX;
    int max = -1;

    for (int h = 0; h <= 256; h++){
        int remove = 0;
        int add = 0;

        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                int diff = map[i][j] - h;

                if (diff > 0){
                    remove += diff;
                }else if (diff < 0){
                    add -= diff;
                }
            }
        }

        if (remove + B >= add){
            int time = remove * 2 + add;

            if (time <= min){
                min = time;
                max = h;
            }
        }
    }
    cout << min << " " << max << endl;



    return 0;
}