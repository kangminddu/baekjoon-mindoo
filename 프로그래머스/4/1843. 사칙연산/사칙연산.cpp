#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int solution(vector<string> arr)
{
    // 숫자와 연산자 분리
    vector<int> nums;
    vector<char> ops;
    for (auto& s : arr){
        if (s == "+" || s == "-") ops.push_back(s[0]);
        else nums.push_back(stoi(s));
    }
    
    int n = nums.size();
    
    vector<vector<int>> maxDP(n, vector<int>(n, INT_MIN));
    vector<vector<int>> minDP(n, vector<int>(n, INT_MAX));
    
    for (int i = 0; i < n; i++){
        maxDP[i][i] = nums[i];
        minDP[i][i] = nums[i];
    }
    
    for (int len = 2; len <= n; len++){
        for (int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            
            for (int k = i; k < j; k++){
                char op = ops[k];
                
                if (op == '+'){
                    maxDP[i][j] = max(maxDP[i][j], maxDP[i][k] + maxDP[k+1][j]);
                    minDP[i][j] = min(minDP[i][j], minDP[i][k] + minDP[k+1][j]);
                }else{
                    maxDP[i][j] = max(maxDP[i][j], maxDP[i][k] - minDP[k+1][j]);
                    minDP[i][j] = min(minDP[i][j], minDP[i][k] - maxDP[k+1][j]);
                }
            }
        }
    }
    return maxDP[0][n-1];
}