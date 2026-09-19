#include <bits/stdc++.h>

using namespace std;

const int kMod = 10007;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long gsum(long long l, long long mod) {
    if (l < 2) return l;
    if (l % 2 == 0) {
        return (gsum(l / 2, mod) * (1 + power(10, l / 2, mod))) % mod;
    }
    return (1 + 10 * gsum(l - 1, mod)) % mod;
}
int main() {
    int k;
    long long m, x = 0;
    cin >> k >> m;

    vector<pair<int, int>> blocks(k);
    for (int i = 0; i < k; i++) {
        cin >> blocks[i].first >> blocks[i].second;
        x += blocks[i].second;
    }

    long long ans = 0, rsum = 0, xMod = kMod * m;
    for (int i = 0; i < k; ++i) {
        long long l = blocks[i].second;
        x -= l;
        int c = blocks[i].first;

        long long r = (c * gsum(l, m)) % m * power(10, x, m) % m;
        long long term = (c * gsum(l, xMod)) % xMod * power(10, x, xMod) % xMod;
        long long q = ((term - r + xMod) % xMod) / m;

        ans = (ans + q) % kMod;
        rsum += r;
        if (rsum >= m) {
            ans = (ans + rsum / m) % kMod;
            rsum %= m;
        }
    }
    cout << ans << endl;
    return 0;
}