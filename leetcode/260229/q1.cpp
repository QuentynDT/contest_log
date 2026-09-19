#include "../timer.h"

class Solution {
public:
    string trimTrailingVowels(string s) {
        auto iv = [&](char& c) -> bool {
            return string("aeiou").find(c) != string::npos;
        };
        int i = 0;
        for(i = s.size() - 1; i >= 0; i--){
            if(!iv(s[i])) break;
        }
        return s.substr(0, i + 1);
    }
};

struct token {
    string s;
    string ans;
    string res;
};

void handle(token& data){
    Solution s;
    data.res = s.trimTrailingVowels(data.s);
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
    tokens.push_back({"idea", "id"});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}