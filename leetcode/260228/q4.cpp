#include "../timer.h"

class Solution {
public:
    int sumOfNumbers(int l, int r, int k) {
        
    }
};

struct token {
    int l;
    int r;
    int k;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.sumOfNumbers(data.l, data.r, data.k);
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
    tokens.push_back({});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}