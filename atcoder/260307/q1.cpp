#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, x, y;
	cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> y;
        if(y < x){
            x = y;
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}