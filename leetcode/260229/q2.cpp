#include "../timer.h"

class Solution {
public:
    int minCost(int n) {
        return (n * (n - 1)) / 2;
    }
};

struct token {
    int n;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.minCost(data.n);
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
    tokens.push_back({4,6});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}