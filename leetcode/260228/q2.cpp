#include "../timer.h"

class Solution {
public:
    string mergeCharacters(string s, int k) {
        const int n = s.size();
        vector<int> last(26, -(k + 1));
        for(int i = 0; i < s.size(); i++){
            if(i - last[s[i] - 'a'] <= k){
                s.erase(i, 1);
                i--;
            } else {
                last[s[i] - 'a'] = i;
            }
        }
        return s;
    }
};

struct token {
    string s;
    int k;
    string ans;
    string res;
};

void handle(token& data){
    Solution s;
    data.res = s.mergeCharacters(data.s, data.k);
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
    tokens.push_back({"abca", 3, "abc"});
    tokens.push_back({"aabca", 2, "abca"});
    tokens.push_back({"yybyzybz", 2, "ybzybz"});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}