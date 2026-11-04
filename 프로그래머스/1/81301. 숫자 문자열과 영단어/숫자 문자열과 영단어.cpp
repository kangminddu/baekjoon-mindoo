#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string words[10] = {"zero", "one", "two", "three", "four",
                       "five", "six", "seven", "eight", "nine"};
    
    for (int d = 0; d < 10; d++){
        size_t pos;
        while ((pos = s.find(words[d])) != string::npos){
            s.replace(pos, words[d].size(), to_string(d));
        }
    }
    
    return stoi(s);
}