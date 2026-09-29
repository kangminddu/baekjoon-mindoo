#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> total;
    unordered_map<string, vector<int>> songs;

    for (int i = 0; i < genres.size(); i++) {
        total[genres[i]] += plays[i];
        songs[genres[i]].push_back(i);
    }

    vector<string> order;
    for (const auto& p : total) order.push_back(p.first);
    sort(order.begin(), order.end(), [&](const string& a, const string& b) {
        return total[a] > total[b];
    });

    vector<int> answer;
    for (const string& g : order) {
        vector<int>& v = songs[g];
        sort(v.begin(), v.end(), [&](int a, int b) {
            if (plays[a] != plays[b]) return plays[a] > plays[b];
            return a < b;
        });
        for (int k = 0; k < v.size() && k < 2; k++) answer.push_back(v[k]);
    }
    return answer;
}