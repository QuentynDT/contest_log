#include <bits/stdc++.h>

using namespace std;
vector<int> digits(long long x, int& front){
    vector<int> v;
    while(x >= 10){
        v.push_back(x % 10);
        x /= 10;
    }
    front = x;
    v.push_back(x);
    ranges::sort(v, ranges::greater());
    return v;
}
void solve(){
    long long x;
    cin >> x;
    int front;
    vector<int> digs = digits(x, front);
    int sum = accumulate(digs.begin(), digs.end(), 0);
    if(sum < 10){
        cout << "0\n";
        return;
    }
    const int n = digs.size();
    int count = 0;
    for(int i = 0; i < n; i++){
        sum -= digs[i];
        if(digs[i + 1] < front){
            sum++;
        }
        count++;
        if(sum < 10){
            cout << count << '\n';
            return;
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