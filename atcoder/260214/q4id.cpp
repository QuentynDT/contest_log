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
            cout << "Next piece: " << hh[i1] << ' ' << ww[i1] << '\n';
            w -= ww[i1];
            cout << "New dimensions: " << h << " * " << w << '\n';
            hh[i1] = 1;
            ww[i1] = w + 1;
            cout << "This piece is located at 1, " << w + 1 << '\n';
            h1.pop();
        }
        else if(p2 == w){
            seen[i2] = true;
            cout << "Next piece: " << hh[i2] << ' ' << ww[i2] << '\n';
            h -= hh[i2];
            cout << "New dimensions: " << h << " * " << w << '\n';
            hh[i2] = h + 1;
            ww[i2] = 1;
            cout << "This piece is located at " << h + 1 << ", 1" << '\n';
            h2.pop();
        } else {
            cout << "We have an error\n";
            cout << "h is " << h << " and w is " << w << '\n';
            cout << "p1, i1 is " << p1 << ", " << i1 << '\n';
            cout << "p2, i2 is " << p2 << ", " << i2 << '\n';
            break;
        }
    }
    cout << "answers\n\n\n";
    for(int i = 0; i < n; i++){
        cout << hh[i] << ' ' << ww[i] << '\n';
    }
    return 0;
}