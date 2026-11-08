#include "../timer.h"

class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        const int n = target.size();
        vector<int> cnt(100001, 0);
        for(int i = 0; i < n; i++){
            cnt[nums[i]]++;
            cnt[target[i]]--;
        }
        for(int v : cnt){
            if(v != 0) return 0;
        }
        int b = 0;
        for(int i = n - 2; i >= 0; i--){
            if(target[i] < target[i + 1]) {
                b = i + 1;
                break;
            }
        }
        for(int i = 0; i < b; i++){
            if(nums[i] != target[i]) {
                return 0;
            }
        }
        int ans = 0;
        for(int i = b; i < n; i++){
            ans++;
            if(nums[i] != target[i]) {
                break;
            }
        }
        return ans;
    }
};

struct token {
    vector<int> nums;
    vector<int> target;
    int ans;
    int res;
};

void handle(token& data) {
    Solution s;
    data.res = s.countSuffix(data.nums, data.target);
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
    tokens.push_back({{1, 2, 3}, {3, 2, 1}, 1});
    tokens.push_back({{1,5,6,4,6}, {1, 5, 6, 6, 4}, 2});
    tokens.push_back({{7, 6, 8}, {8, 6, 7}, 0});
    tokens.push_back({{1}, {1}, 1});

    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();

    showRunTime(start, end);
}
