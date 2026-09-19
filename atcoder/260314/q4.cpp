#include <bits/stdc++.h>

using namespace std;
int f(int x){
    return 2 * x * (x + 1) - x;
}
int solve(int l, int r, int d, int u){
    int sqs = min(r, u);
    return f(sqs/2);
    //0 3 0 7 0 11 0 
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int l, r, d, u, ans = 0, x = 0;
    cin >> l >> r >> d >> u;
    if(r > 0 && u > 0){
        int y = min(r, u);
        x += f(y / 2);
        if(r > y){
            x += u * (2 * r/2 - )
        }
    }
    if(l < 0 && u > 0){
        x += f(min(-l, u) / 2);
    }
    cout << x << '\n';
    return 0;
    // for(int i = -5; i < 5; i++){
    //     for(int j = -5; j < 5; j++){
    //         if(abs(i) > abs(j)) cout << i << ", " << j << '\n';
    //     }
    // }
    for(int i = l; i <= r; i++){
        //cout << "Single column from " << d << " to " << u << " at x coord: " << i << '\n';
        if(i <= min(d, -u) || i >= max(-d, u)){
            if(i % 2 == 0) ans += (u - d + 1);
            //cout << "out of bounds\n";
        } else {
            cout << i << " is in bounds\n";
        }
    }
    cout << ans << '\n';
    return 0;
}