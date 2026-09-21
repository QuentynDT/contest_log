#include "../timer.h"

class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        ranges::sort(intervals);
        int ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(intervals[j][1] >= intervals[i][0]) ans++;
            }
        }
        return ans;
    }
};

struct token {
    vector<vector<int>> intervals;
    int ans;
    int res;
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
