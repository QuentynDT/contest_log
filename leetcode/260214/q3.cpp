#include "../timer.h"

class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        const size_t n = nums.size();
        long long a = 0, b = 0, c = 0;
        for(int i = 0; i < n; i++){
            if(i == 0 || colors[i] != colors[i - 1]){
                c = 1LL * nums[i] + max(b, a);
            } else {
                c = max(b, 1LL * nums[i] + a);
            }
            a = b, b = c;
        }
        return b;
    }
};

struct token {
    vector<int> nums;
    vector<int> colors;
    long long ans;
    long long res;
};

void handle(token& data){
    Solution s;
    data.res = s.rob(data.nums, data.colors);
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
    tokens[0] = {{1, 4, 3, 5}, {1, 1, 2, 2}, 9};
    tokens[1] = {{3, 1, 2, 4}, {2, 3, 2, 2}, 8};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}