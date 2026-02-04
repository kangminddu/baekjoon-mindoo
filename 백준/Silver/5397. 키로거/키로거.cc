#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    list<char> L;
    
    while (t--){
        string L;
        cin >> L;

        list<char> pwd;
        auto cursor = pwd.end();

        for (auto c : L){
            if (c == '<'){
                if (cursor != pwd.begin()){
                    cursor--;
                }
            }
            else if (c == '>'){
                if (cursor != pwd.end()){
                    cursor++;
                }
            }
            else if (c == '-'){
                if (cursor != pwd.begin()){
                    cursor--;
                    cursor = pwd.erase(cursor);
                }
            }
            else{
                pwd.insert(cursor, c);
            }
        }
        for (char c : pwd){
            cout << c;
        }
        cout << endl;
    }

    return 0;
}