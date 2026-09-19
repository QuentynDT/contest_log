#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<bool> seen(m, false);
    for(int i = 0; i < n; i++){
        int l, ans = 0;
        cin >> l;
        for(int j = 0; j < l; j++){
            int x;
            cin >> x;
            if(ans) continue;
            if(!seen[x - 1]){
                seen[x - 1] = true;
                ans = x;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}