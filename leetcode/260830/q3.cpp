#include "../timer.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF = 1e9;
        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        for (int x : nums) {
            vector<pair<int, int>> opt;
            for (long long v = x, cost = 0; v <= sum; v *= 2, cost++) opt.push_back({v, cost});
            for (long long v = x / 2, cost = 1; v > 0; v /= 2,cost++) opt.push_back({v, cost});
            vector<int> ndp = dp;
            for (auto [v, cost] : opt) {
                for (int s = 0; s + v <= sum; s++) {
                    if (dp[s] != INF) ndp[s + v] = min(ndp[s + v], dp[s] + cost);
                }
            }
            dp = move(ndp);
        }
        return dp[sum] == INF ? -1 : dp[sum];
    }
};

struct token {
    vector<int> nums;
    int sum;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.minOperations(data.nums, data.sum);
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
    tokens.push_back({{5, 6, 10}, 4, 3});
    tokens.push_back({{10, 2}, 13, 3});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
