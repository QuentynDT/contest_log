#include "../timer.h"

class Solution {
public:
    int minDays(int n) {
        int sz = 141;
        vector<int> sums(sz);
        sums[1] = 1;
        for(int i = 2; i < sz; i++){
            sums[i] = i + sums[i - 1];
        }
        vector<int> dp(n + 1, n * 2);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; ; j++){
                if(sums[j] > i) break;
                if(i == sums[j]){
                    dp[i] = j;
                } else {
                    dp[i] = min(dp[i], dp[i - sums[j]] + 1 + j);
                }
                //dp[i - sums[j]] + 1 + j = dp[i] + 1 + dp[sums[j]] -> dp[sum[j]] = j
            }
            //dp[3] + 1 + dp[7] = dp[10]
        }
        return dp[n];
    }
};

struct token {
    int n;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.minDays(data.n);
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
//1 3 6 10 15 21 28 36 45 55 66 78
int main(){
    const int n = 1;
    vector<token> tokens;
    tokens.push_back({2, 3});
    tokens.push_back({9, 6});
    tokens.push_back({30, 7});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
