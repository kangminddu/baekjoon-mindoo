#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    unordered_set<string> uniq(report.begin(), report.end());
    unordered_map<string, int> reported_cnt;
    vector<pair<string, string>> pairs;
    
    for (const string& r : uniq){
        stringstream ss(r);
        string from, to;
        ss >> from >> to;
        reported_cnt[to]++;
        pairs.push_back({from,to});
    }
    
    unordered_map<string, int> idx;
    for (int i = 0; i < id_list.size(); i++) idx[id_list[i]] = i;
    
    for (const auto& p : pairs){
        if (reported_cnt[p.second] >= k) answer[idx[p.first]]++;
    }
    return answer;
}