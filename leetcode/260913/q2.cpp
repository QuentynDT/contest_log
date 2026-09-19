#include "../timer.h"

class Solution {
    inline static vector<vector<long long>> ps = []() {
        vector<vector<long long>> res(2);
        for (int l = 1; l <= 10; l++) {
            int hl = (l + 1) / 2;
            long long start = 1;
            for (int i = 1; i < hl; ++i) start *= 10;
            long long end = start * 10;

            for (long long half = start; half < end; half++) {
                string s = to_string(half);
                string rev = s;
                reverse(rev.begin(), rev.end());

                string pal_str = (l % 2 == 0) ? (s + rev) : (s + rev.substr(1));
                long long p = stoll(pal_str);
                if (p > 2000000002LL) continue;
                res[p % 2].push_back(p);
            }
        }
        ranges::sort(res[0]);
        ranges::sort(res[1]);
        return res;
    }();
public:
    long long minOperations(vector<int>& nums) {
        long long ans = 0;
        for (int& x : nums) {
            const vector<long long>& pals = ps[x % 2];
            auto it = lower_bound(pals.begin(), pals.end(), (long long)x);
            long long diff = *it - x;
            if (it != pals.begin()) {
                diff = min(diff, (long long)x - *(it - 1));
            }
            ans += diff / 2;
        }
        return ans;
    }
};

struct token {
    vector<int> nums;
    long long ans;
    long long res;
};

void handle(token& data){
    Solution s;
    data.res = s.minOperations(data.nums);
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
    tokens.push_back({{1, 2, 1000000000, 999999999, 1000000001}, 9});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
