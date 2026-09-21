#include "../timer.h"

class Solution {
public:
    long long maxValue(vector<int>& nums) {
        const int n = nums.size();
        auto add = [&](int i) -> long long {
            if(i % 2 == 0) return nums[i];
            return -nums[i];
        };

        long long total_sum = 0;
        for(int i = 0; i < n; i++){
            total_sum += add(i);
        }

        vector<long long> P(n + 1, 0);
        for(int i = 0; i < n; i++){
            P[i + 1] = P[i] + add(i);
        }

        long long max_delta = 0, max_A0 = -1e18, max_A1 = -1e18;

        for(int r = 1; r < n; r++){
            int l = r - 1;
            long long c_l = add(l);
            long long A0_l = 2 * P[l + 1] - c_l + nums[l];
            long long A1_l = 2 * P[l + 1] - c_l - nums[l];

            if(A0_l > max_A0) max_A0 = A0_l;
            if(A1_l > max_A1) max_A1 = A1_l;

            long long delta = 0;
            if(r % 2 == 0) {
                delta = max_A0 - 2 * P[r + 1];
            } else {
                delta = max_A1 - 2 * P[r + 1];
            }

            if(delta > max_delta) max_delta = delta;
        }

        return total_sum + max_delta;
    }
};

struct token {
    vector<int> nums;
    long long ans;
    long long res;
};

void handle(token& data) {
    Solution s;
    data.res = s.maxValue(data.nums);
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
    tokens.push_back({{1, 5, 2}, 6});
    tokens.push_back({{6, 4, 3}, 7});
    tokens.push_back({{10, 1, 10, 1}, 18});
    tokens.push_back({{10, 100, 10, 1}, 99});

    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();

    showRunTime(start, end);
}
