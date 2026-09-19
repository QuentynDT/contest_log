#include "../timer.h"

class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int mx = 0, ans = 0;
        for(int& x : lights){
            mx = max(mx, x);
        }
        for(int& x : arrivalTime){
            x %= period;
            if(x >= mx){
                ans = max(ans, period - x);
            }
        }
        return ans;
    }
};

struct token {
    int period;
    vector<int> lights;
    vector<int> arrivalTime;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.minPenalty(data.period, data.lights, data.arrivalTime);
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
    tokens.push_back({8, {2, 3}, {2, 5, 8, 11}, 5});
    tokens.push_back({10, {3, 6, 8}, {4, 9, 15}, 1});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
