#include "../timer.h"

class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        const int n = nums.size();
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            string s;
            for (int bit = 26; bit >= 0; bit--) {
                if (x & (1 << bit)) {
                    if (bit == 26) {
                        s += "zz";
                    } else {
                        s += char('a' + bit);
                    }
                }
            }
            ans[i] = s;
        }
        return ans;
    }
};

struct token {
    vector<int> nums;
    vector<string> ans;
    vector<string> res;
};

void handle(token& data){
    Solution s;
    data.res = s.largestString(data.nums);
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
    tokens.push_back({{2, 5, 7}, {"b", "ca", "cba"}});
    tokens.push_back({{3, 9, 1}, {"ba", "da", "a"}});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
