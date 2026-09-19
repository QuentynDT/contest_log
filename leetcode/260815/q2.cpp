#include "../timer.h"

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        auto dist = [&](char a, char b) {
            int x = a - 'a';
            int y = b - 'a';
            int d = (y - x + 26) % 26;
            return min(d, 26 - d);
        };
        int ans = INT_MAX;
        for (int k = 0; k < n; k++) {
            int cur = k;
            for (int i = 0; i < n / 2; i++) {
                char left  = s[(i + k) % n];
                char right = s[(n - 1 - i + k) % n];
                cur += dist(left, right);
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};

struct token {
    string s;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.minOperations(data.s);
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
    tokens.push_back({"abc", 2});
    tokens.push_back({"yb", 3});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
