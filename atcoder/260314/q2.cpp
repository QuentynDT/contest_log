#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int h, w, q;
	cin >> h >> w >> q;
    for(int i = 0; i < q; i++){
        int x, v;
        cin >> x >> v;
        if(x == 1){
            cout << v * w << '\n';
            h -= v;
        } else {
            cout << h * v << '\n';
            w -= v;
        }
    }
    return 0;
}