#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    string s, t = "ab";
    cin >> n;
    cin >> s;
    bool possible = true;
    int l = 0, r = (n & 1) ^ 1;
    for(int i = 0; i < n; i++){
        char &c = s[i];
        if(c != '?'){
            if(c != t[l] && c != t[r]){
                possible = false;
                break;
            }
            if(c == t[l]){
                l ^= 1;
            } else {
                r ^= 1;
            }
            continue;
        }
        
        if(i == n - 1 || r == l){
            l ^= 1;
        } else {
            i++;
        }
    }
    if (possible) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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