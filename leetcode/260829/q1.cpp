#include "../timer.h"

class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if((source[0] + source[1] + target[0] + target[1]) % 2 == 1) return -1;
        if(abs(source[0] - target[0]) == abs(source[1] - target[1])) return 1;
        return 2;
    }
};

struct token {
    vector<int> source;
    vector<int> target;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.minBishopMoves(data.source, data.target);
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
    const int n = 2;
    vector<token> tokens;
    tokens.push_back({{8, 1}, {1, 8}, 1});
    tokens.push_back({{4, 2}, {1, 3}, 2});
    tokens.push_back({{4, 2}, {1, 4}, -1});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
