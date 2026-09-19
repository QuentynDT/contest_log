#include "../timer.h"

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> seen(100);
        for(int& bulb : bulbs){
            seen[bulb - 1] = !seen[bulb - 1];
        }
        vector<int> ans;
        for(int i = 0; i < 100; i++){
            if(seen[i]) ans.push_back(i + 1);
        }
        return ans;
    }
};

struct token {
    vector<int> bulbs;
    vector<int> ans;
    vector<int> res;
};

void handle(token& data){
    Solution s;
    data.res = s.toggleLightBulbs(data.bulbs);
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
    vector<token> tokens(n);
    tokens[0] = {{10,30,20,10}, {20, 30}};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}