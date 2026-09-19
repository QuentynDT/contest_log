#include "../timer.h"

class Solution {
public:
    bool isPalindromic(string s) {
        string l;
        for(char& c : s){
            l += bitset<8>((int)c).to_string();
        }
        const int n = l.size();
        cout << l << '\n';
        for(int i = 0; i < n/2; i++){
            if(l[i] != l[n - i - 1]) return false;
        }
        return true;
    }
};

struct token {
    string s;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.isPalindromic(data.s);
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
    tokens.push_back({"ff", true});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
