#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int h, w, n;
	cin >> h >> w >> n;
    vector<int> hh(n), ww(n);
    priority_queue<pair<int, int>> h1;
    priority_queue<pair<int, int>> h2;
    for(int i = 0; i < n; i++){
        cin >> hh[i] >> ww[i];
        h1.push({hh[i], i});
        h2.push({ww[i], i});
    }
    vector<bool> seen(n);
    bool done = false;
    while(!h1.empty() && !h2.empty()){
        auto& [p1, i1] = h1.top();
        auto& [p2, i2] = h2.top();
        while(seen[i1]){
            h1.pop();
            if(h1.empty()){
                done = true;
                break;
            }
            auto& [p1, i1] = h1.top();
        }
        while(seen[i2]){
            h2.pop();
            if(h2.empty()){
                done = true;
                break;
            }
            auto& [p2, i2] = h2.top();
        }
        if(done) break;
        if(p1 == h){
            seen[i1] = true;
            w -= ww[i1];
            hh[i1] = 1;
            ww[i1] = w + 1;
            h1.pop();
        }
        else if(p2 == w){
            seen[i2] = true;
            h -= hh[i2];
            hh[i2] = h + 1;
            ww[i2] = 1;
            h2.pop();
        }
    }
    for(int i = 0; i < n; i++){
        cout << hh[i] << ' ' << ww[i] << '\n';
    }
    return 0;
}