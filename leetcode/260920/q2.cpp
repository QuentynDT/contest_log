#include "../timer.h"

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        vector<int> s(n));
        for(int i = 0; i < n; i++){
            s[i] = intervals[i][0];
        }
        ranges::sort(s);
        long long ans = 1LL * n * (n - 1) / 2;
        for(int i = 0; i < n; i++){
            auto it = upper_bound(s.begin(), s.end(), intervals[i][1]);
            ans -= distance(it, s.end());
        }
        return ans;
    }
};

struct token {
    vector<vector<int>> intervals;
    long long ans;
    long long res;
};

void handle(token& data) {
    Solution s;
    data.res = s.countIntersectingIntervals(data.intervals);
}

void runTests(vector<token>& tokens) {
    cout << '\n';
    for(token& t : tokens) {
        handle(t);
        cout << "Output:   ";
        display(t.res);
        cout << "\nExpected: ";
        display(t.ans);
        cout << "\n\n";
    }
}

int main() {
    const int n = 1;
    vector<token> tokens;
    tokens.push_back({{{1,2},{2,3},{3,4}}, 2});

    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();

    showRunTime(start, end);
}
