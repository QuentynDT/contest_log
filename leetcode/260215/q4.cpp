#include "../timer.h"

class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
        
    }
};

struct token {
    vector<int> nums;
    int k;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxXor(data.nums, data.k);
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
    vector<token> tokens(n);
    tokens[0] = {};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}