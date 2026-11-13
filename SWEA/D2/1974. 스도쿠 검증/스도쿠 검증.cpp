#include<iostream>
#include <vector>
using namespace std;

bool valid(const vector<int>& nums){
	bool seen[10] = {false};
    for (int v : nums){
    	if (seen[v]) return false;
        seen[v] = true;
    }
    return true;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<vector<int>> arr(9, vector<int>(9,0));
		for (int i = 0; i < 9; i++){
        	for (int j = 0; j < 9; j++){
            	cin >> arr[i][j];
            }
        }
        bool correct = true;
        for (int i = 0; i < 9; i++){
        	if (!valid(arr[i])) correct = false;
        }
        for (int j = 0; j < 9; j++){
        	vector<int> col;
            for (int i = 0; i < 9; i++) col.push_back(arr[i][j]);
            if (!valid(col)) correct = false;
        }
        
        for (int br = 0; br < 3; br++){
        	for (int bc = 0; bc < 3; bc++){
            	vector<int> box;
                for (int i = br * 3; i < br * 3 + 3; i++)
					for (int j = br * 3; j < br * 3 + 3; j++)
                    	box.push_back(arr[i][j]);
				if (!valid(box)) correct = false;                	
            }
        }
        cout << "#" << test_case << " " << (correct ? 1 : 0) << "\n";
	}
	return 0;
}