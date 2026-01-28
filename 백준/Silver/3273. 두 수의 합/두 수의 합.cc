#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int x;
    cin >> x;

    sort(arr.begin(), arr.end());

    int answer = 0;
    int left = 0;
    int right = n - 1;

    while (left < right){
        int sum = arr[left] + arr[right];
        
        if (sum == x){
            answer++;
            left++;
            right--;
        } else if (sum < x) {
            left++;
        } else{
            right--;
        }
    }
    cout << answer << endl;
}