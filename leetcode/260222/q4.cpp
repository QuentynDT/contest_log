#include "../timer.h"

class Solution {
public:
    struct Fraction {
        long long num, den;
        void simplify() {
            long long div = gcd(num, den);
            num /= div;
            den /= div;
        }
        bool operator<(const Fraction& other) const {
            if (num != other.num) return num < other.num;
            return den < other.den;
        }
        
        bool operator==(long long k) const {
            return den == 1 && num == k;
        }
    };
    int countSequences(vector<int>& nums, long long k) {
        map<pair<int, Fraction>, int> memo;
        const int n = nums.size();

        auto dfs = [&](this auto self, int i, Fraction x) -> int {
            if (i == n) return x == k;
            
            if (memo.count({i, x})) return memo[{i, x}];
            Fraction mul = {x.num * nums[i], x.den};
            mul.simplify();
            Fraction div = {x.num, x.den * nums[i]};
            div.simplify();
            memo[{i, x}] = self(i + 1, mul) + self(i + 1, div) + self(i + 1, x);
            return memo[{i, x}];
        };

        return dfs(0, {1, 1});
    }
};

struct token {
    vector<int> nums;
    long long k;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.countSequences(data.nums, data.k);
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
    vector<token> tokens(n);
    tokens[0] = {{2,3,2}, 6, 2};
    tokens[1] = {{4,6,3}, 2, 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}