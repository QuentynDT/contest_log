#include "../timer.h"

class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        const int sz = requests.size();
        int ans = requests[0];
        for(int i = 1; i < sz; i++){
            ans += abs(requests[i] - requests[i - 1]);
        }
        return ans;
    }
};

struct token {
    int n;
    vector<int> requests;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.elevatorRequests(data.n, data.requests);
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
    tokens.push_back({5, {2, 1, 4, 3}, 7});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
