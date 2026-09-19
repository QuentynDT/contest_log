#include <bits/stdc++.h>

using namespace std;
void sim(vector<int>& arr, int idx){
    for(int i = 0; i < idx; i++){
        arr[i] += arr[idx];
    }
    for(int i = arr.size() - 1; i >= idx; i--){
        arr[i] -= arr[idx];
    }
}
void disp(vector<int>& arr){
    for(int& x : arr){
        cout << x << ' ';
    }
    cout << '\n';
}
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int sz = 1;
    vector<int> nd = {arr[0]};
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[i - 1]){
            nd.push_back(arr[i]);
            sz++;
            if(sz > 2 || nd[1] + nd[0] != 0){
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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