#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;
	cin >> s;
    vector<int> ans;
    int zc = 0, oc = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            oc++;
            ans.push_back(i + 1);
        }
    }
    zc = n - oc;
    if(oc % 2 == 1 && zc % 2 == 0){
        cout << "-1";
    } else if(oc % 2 == 0 && zc % 2 == 1 && oc < zc || oc % 2 == 0){
        cout << oc << '\n';
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                cout << i + 1 << ' ';
            }
        }
    } else if(oc % 2 == 0 && zc % 2 == 1 && oc > zc || zc % 2 == 1){
        cout << zc << '\n';
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                cout << i + 1 << ' ';
            }
        }
    }
    cout << '\n';
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