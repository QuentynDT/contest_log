#include "../timer.h"

class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        int g = 0;
        for (const string& w : words) {
            if (w.size() >= k) {
                freq[w.substr(0, k)]++;
            }
        }
        for (auto& [pre, count] : freq) {
            if (count >= 2) {
                g++; 
            }
        }
        return g;
    }
};

struct token {
    vector<string> words;
    int k;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.prefixConnected(data.words, data.k);
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
    tokens[0] = {{"apple","apply","banana","bandit"}, 2, 2};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}