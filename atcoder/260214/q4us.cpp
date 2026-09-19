#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int h, w, n;
	cin >> h >> w >> n;
    vector<int> hs(n), ws(n);
    unordered_map<int, vector<int>> hq, wq;
    for(int i = 0; i < n; i++){
        cin >> hs[i] >> ws[i];
        hq[hs[i]].push_back(i);
        wq[ws[i]].push_back(i);
    }
    vector<bool> seen(n);
    for(int i = 0; i < n; i++){
        vector<int>& hv = hq[h];
        vector<int>& wv = wq[w];
        for(int& idx : hv){
            if(seen[idx]) continue;
            seen[idx] = true;
            w -= ws[idx];
            hs[idx] = 1;
            ws[idx] = w + 1;
        }
        for(int& idx : wv){
            if(seen[idx]) continue;
            seen[idx] = true;
            h -= hs[idx];
            hs[idx] = h + 1;
            ws[idx] = 1;
        }
    }
    cout << '\n';
    for(int i = 0; i < n; i++){
        cout << hs[i] << ' ' << ws[i] << '\n';
    }
    return 0;
}