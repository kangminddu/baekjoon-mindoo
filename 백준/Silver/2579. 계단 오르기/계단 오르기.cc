#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> game(n+1);
    for (int i = 1; i <= n; i++){
        cin >> game[i];
    }
    vector<int> dp(n+1);
    dp[1] = game[1];
    
    if (n >= 2){
        dp[2] = game[1] + game[2];
    }

    for (int i = 3; i <= n; i++){
        dp[i] = max(dp[i-2], dp[i-3] + game[i-1]) + game[i];
    }
    cout << dp[n] << endl;
    return 0;
}