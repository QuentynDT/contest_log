#include "../timer.h"
int f[10];

int init = []() {
    f[0] = 1;
    for (int i = 1; i < 10; i++) {
        f[i] = i * f[i - 1];
    }
    return 0;
}();
class Solution {
public:
    int df(int n){
        int sum = 0;
        while(n){
            sum += f[n % 10];
            n /= 10;
        }
        return sum;
    }
    void build(vector<int>& digs, int a, int b){
        while(a){
            digs[a % 10]++;
            a /= 10;
        }
        while(b){
            digs[b % 10]--;
            b /= 10;
        }
    }
    bool isDigitorialPermutation(int n) {
        int sum = df(n);
        vector<int> digs(10);
        build(digs, sum, n);
        for(int i = 0; i < 10; i++){
            if(digs[i] != 0) return false;
        }
        return true;
    }
};

struct token {
    int n;
    bool ans;
    bool res;
};

void handle(token& data){
    Solution s;
    data.res = s.isDigitorialPermutation(data.n);
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
    vector<token> tokens(n);
    tokens[0] = {145, true};
    tokens[1] = {10, false};
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}