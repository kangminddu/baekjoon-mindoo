    #include <iostream>
    #include <list>
    #include <string>
    using namespace std;

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);

        string first;
        cin >> first;

        list<char> L;
        for (char c : first){
            L.push_back(c);
        }

        auto cursor = L.end();

        int m;
        cin >> m;

        while (m--){
            char cmd;
            cin >> cmd;

            if (cmd == 'P'){
                char add;
                cin >> add;
                L.insert(cursor, add);
            }
            else if (cmd == 'L'){
                if (cursor != L.begin()){
                    cursor--;
                }
            }
            else if (cmd == 'D'){
                if (cursor != L.end()){
                    cursor++;
                }
            }
            else if (cmd == 'B'){
                if (cursor != L.begin()){
                    cursor--;
                    cursor = L.erase(cursor);
                }
            }
        }

        for (char c : L){
            cout << c;
        }
        cout << endl;
        return 0;
    }