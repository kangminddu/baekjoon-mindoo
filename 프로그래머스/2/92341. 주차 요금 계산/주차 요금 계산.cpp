#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, int> inTime; // 차량 번호 - 입차시간
    map<string, int> totalTime; // 차량번호 -> 누적 주차 시간
    
    for (const  string& record : records){
        int time = stoi(record.substr(0,2)) * 60 + stoi(record.substr(3,2));
        string  car = record.substr(6,4);
        string type = record.substr(11);
        
        if (type == "IN"){
            inTime[car] = time;
        }
        else{
            totalTime[car] += time - inTime[car];
            inTime.erase(car);
        }
            
    }
    int endTime = 23 * 60 + 59;
    for (const auto& [car, time] : inTime){
        totalTime[car] += endTime - time;
    }
    vector<int> answer;
    for (const auto& [car, minutes] : totalTime){
        int fee = fees[1];
        if (minutes > fees[0]){
            int extra = minutes - fees[0];
            int units = (extra + fees[2] - 1) / fees[2];
            fee += units * fees[3];
        }
        answer.push_back(fee);
    }
    return answer;
}