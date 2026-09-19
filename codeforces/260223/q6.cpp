#include <bits/stdc++.h>

using namespace std;
const int MAXN = 25001;
bitset<MAXN> rows[MAXN];
int counts[MAXN];


void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        rows[i].reset();
        counts[i] = 0;
    }

    bool possible = true;
    int midx = 1;

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;

        rows[r].set(c);
        counts[r]++;

        if (counts[r] > counts[midx]) {
            midx = r;
        }
        
        bool curr = true;
        
        if (curr) cout << "YES" << endl;
        else {
            cout << "NO" << endl;
            possible = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
	cin >> t;
    while(t--){
        solve();
    }
    return 0;
}