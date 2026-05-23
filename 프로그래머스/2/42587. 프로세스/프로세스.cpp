#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++){
        q.push({priorities[i], i});
        
    }
    while (!q.empty()){
        int priority = q.front().first;
        int idx = q.front().second;
        q.pop();
        bool higher = false;
        
        queue<pair<int,int>> temp = q;
        
        while (!temp.empty()){
            if (temp.front().first > priority){
                higher = true;
                break;
            }
            temp.pop();
        }
        if (higher){
            q.push({priority, idx});
        }else{
            answer++;
            if (idx == location) return answer;
        }
    }
    return answer;
}