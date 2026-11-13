#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int N;
    cin >> N;
    vector<int> arr(N, 0);
    for (int i = 0; i < arr.size(); i++){
    	cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int size = arr.size() / 2;
    cout << arr[size];
    
	return 0;
}