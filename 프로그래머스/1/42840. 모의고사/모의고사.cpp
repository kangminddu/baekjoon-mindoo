#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> patterns = {
        {1,2,3,4,5},
        {2,1,2,3,2,4,2,5},
        {3,3,1,1,2,2,4,4,5,5}
    };
    vector<int> score(3,0);
    
    for (int i = 0; i < answers.size(); i++){
        for (int p = 0; p < 3; p++){
            if (answers[i] == patterns[p][i % patterns[p].size()]){
                score[p]++;
            }
        }    
    }
    
    int best = *max_element(score.begin(), score.end());
    
    for (int p = 0; p < 3; p++){
        if (score[p] == best) answer.push_back(p + 1);
    }
    return answer;
}