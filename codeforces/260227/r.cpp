#include <iostream>
#include <random>

using namespace std;

int rd(int a, int b) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(a, b);
    return dis(gen);
}
vector<int> gp(int n) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 1); // Fills 1, 2, ..., n

    static random_device rd;
    static mt19937 g(rd());

    shuffle(p.begin(), p.end(), g);
    return p;
}
int main() {
    int t = 5;
    cout << t << '\n';
    while(t--){
        int n = rd(5, 10);
        int a = rd(0, n);
        int b = rd(a + 1, n);
        cout << n << ' ' << a << ' ' << b << '\n';
        vector<int> p = gp(n);
        for(int& x : p){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}