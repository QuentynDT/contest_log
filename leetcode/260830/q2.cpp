#include "../timer.h"

class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        constexpr int kMod = 1'000'000'007;
        long long ans = 0;
        auto myPow = [&](long long a, long long b) -> long long {
            a %= kMod;
            long long res = 1;
            while (b > 0) {
                if (b & 1) res = res * a % kMod;
                a = a * a % kMod;
                b >>= 1;
            }
            return res;
        };
        for (long long num : nums) {
            int width = num % 10;
            long long d = num / 10;
            string s = to_string(d);
            long long x = stoll(s.substr(0, width)), y = stoll(s.substr(width));
            ans = (ans + myPow(x, y)) % kMod;
        }
        return ans;
    }
};

struct token {
    vector<long long> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.sumDecoded(data.nums);
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
    tokens.push_back({{231}, 8});
    tokens.push_back({{2522, 2101}, 1649});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
