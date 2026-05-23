#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    
    for (int i = 0; i < progresses.size(); i++){
        if ((100 - progresses[i]) % speeds[i] == 0) days.push_back((100 - progresses[i]) / speeds[i]);
        else days.push_back((100 - progresses[i]) / speeds[i] + 1);
    }
    int current = days[0];
    int count = 1;
    for (int i = 1; i < days.size(); i++){
        if (current >= days[i]) count++;
        else{
            answer.push_back(count);
            current = days[i];
            count = 1;
        }
    }
    answer.push_back(count);
    return answer;
}