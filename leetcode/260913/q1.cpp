#include "../timer.h"

class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            rowShift[i] %= n;
            for(int j = 0; j < n; j++){
                temp[(j - rowShift[i] + n) % n] = grid[i][j];
            }
            grid[i] = temp;
        }
        for(int i = 0; i < n; i++){
            colShift[i] %= n;
            for(int j = 0; j < n; j++){
                temp[(j - colShift[i] + n) % n] = grid[j][i];
            }
            for(int j = 0; j < n; j++){
                grid[j][i] = temp[j];
            }
        }
        return grid;
    }
};

struct token {
    int n;
    vector<vector<int>> grid;
    vector<int> rowShift;
    vector<int> colShift;
    vector<vector<int>> ans;
    vector<vector<int>> res;
};

void handle(token& data){
    Solution s;
    data.res = s.cyclicShift(data.n, data.grid, data.rowShift, data.colShift);
}

void runTests(vector<token>& tokens){
    cout << '\n';
    for(token& t : tokens){
        handle(t);
        cout << "Output: ";
        display(t.res);
        cout << "\nExpected: ";
        display(t.ans);
        cout << "\n\n";
    }
}

int main(){
    const int n = 1;
    vector<token> tokens;
    tokens.push_back({2, {{1, 2}, {3, 4}}, {1, 0}, {0, 1}, {{2, 4}, {3, 1}}});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
