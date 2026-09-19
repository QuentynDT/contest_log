#include "../timer.h"

class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int rem = -1; rem < n; rem++) {
            int m = n;
            if(rem != -1) m--;
            if (m < 2) continue;

            vector<int> arr;

            for (int i = 0; i < n; i++) {
                if (i != rem)
                    arr.push_back(nums[i]);
            }

            vector<int> pref(m), suff(m);

            pref[0] = arr[0];
            for (int i = 1; i < m; i++) {
                pref[i] = gcd(pref[i - 1], arr[i]);
            }

            suff[m - 1] = arr[m - 1];
            for (int i = m - 2; i >= 0; i--) {
                suff[i] = gcd(suff[i + 1], arr[i]);
            }

            int score = 0;

            for (int i = 0; i < m - 1; i++) {
                if (pref[i] == suff[i + 1])
                    score++;
            }

            ans = max(ans, score);
        }

        return ans;
    }
};

struct token {
    vector<int> nums;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maxValidSplits(data.nums);
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
    tokens.push_back({{10, 30, 15, 10}, 2});
    tokens.push_back({{2, 10, 14}, 1});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
