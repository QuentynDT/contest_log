#include "../timer.h"

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        const int n = words.size();
        string ans(n, ' ');
        for(int i = 0; i < n; i++){
            int s = 0;
            for(char& c : words[i]){
                s += weights[c - 'a'];
            }
            ans[i] = 25 - s % 26 + 'a';
        }
        return ans;
    }
};

struct token {
    vector<string> words;
    vector<int> weights;
    string ans;
    string res;
};

void handle(token& data){
    Solution s;
    data.res = s.mapWordWeights(data.words, data.weights);
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
    tokens[0] = {{"abcd","def","xyz"}, {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2}, "rij"};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}