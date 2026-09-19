#include "../timer.h"

class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        unordered_set<int> seen;
        for(int x : grid[0]){
            seen.insert(x);
        }
        for(int i = 1; i < m; i++){
            unordered_set<int> next;
            for(int& x : grid[i]){
                for(int prev : seen){
                    next.insert(prev | x);
                }
            }
            if(next.size() > 1024){
                vector<int> v(next.begin(), next.end());
                nth_element(v.begin(), v.begin() + 1024, v.end());
                next = unordered_set<int>(v.begin(), v.begin() + 1024);
            }
            seen = next;
        }
        return ranges::min(seen);
    }
};

struct token {
    vector<vector<int>> grid;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.minimumOR(data.grid);
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
    tokens.push_back({{{3, 5}, {6, 4}}, 5});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}