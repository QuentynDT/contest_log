#include "../timer.h"

class Solution {
public:
    string maximumXor(string s, string t) {
        vector<int> count(2);
        const int n = s.size();
        for(char& c : t){
            count[c - '0']++;
        }
        for(int i = 0; i < n; i++){
            char &c = s[i];
            if(count['1' - c]){
                count['1' - c]--;
                t[i] = '1';
            } else {
                count[c - '0']--;
                t[i] = '0';
            }
        }
        return t;
    }
};

struct token {
    string s;
    string t;
    string ans;
    string res;
};

void handle(token& data){
    Solution s;
    data.res = s.maximumXor(data.s, data.t);
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
    vector<token> tokens(n);
    tokens[0] = {"101", "011", "110"};
    tokens[1] = {"0110", "1110", "1101"};
    tokens[2] = {"0101", "1001", "1111"};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}