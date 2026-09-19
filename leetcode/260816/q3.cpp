#include "../timer.h"

class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        if (n == 1) return 0;
        int m = station.size();
        vector<int> L(n), R(n);
        int p = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            while (station[p] != skill[i]) p++;
            L[i] = p;
            p++;
        }
        p = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (station[p] != skill[i]) p--;
            R[i] = p;
            p--;
        }
        for (int i = 1; i < n; i++) {
            ans = max(ans, R[i] - L[i - 1]);
        }
        return ans;
    }
};

struct token {
    string skill;
    string station;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.maximumGap(data.skill, data.station);
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
    const int n = 3;
    vector<token> tokens;
    tokens.push_back({"aa", "aaaa", 3});
    tokens.push_back({"xyz", "xyzz", 2});
    tokens.push_back({"cbc", "cbcdbc", 4});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
