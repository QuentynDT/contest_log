#include "../timer.h"

class Solution {
public:
    int kthDigit(long long k) {
        //if(k < 10) return k;
        int dc = 0, d = 1;
        while(dc <= k){
            dc += 9 * pow(10, d - 1) * d;
            d++;
        }
        d--;
        k -= dc - 9 * pow(10, d - 1) * d;
        int pib = k % (10 * d);
        int nb = k / (10 * d);
        cout << nb << ' ' << pib << '\n';
        int sb = pow(10, d - 1) + 10 * nb;
        cout << sb << '\n';
        int nn = pib / d;
        int pin = pib % d;
        cout << nn << ' ' << pin << '\n';
        cout << k << ' ' << d << '\n';
        return 0;
    }
};

struct token {
    long long k;
    int ans;
    int res;
};

void handle(token& data){
    Solution s;
    data.res = s.kthDigit(data.k);
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
    vector<token> tokens;
    tokens.push_back({4, 4});
    tokens.push_back({15, 7});
    tokens.push_back({29, 0});
    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();
    showRunTime(start, end);
}
