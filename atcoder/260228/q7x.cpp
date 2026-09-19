#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> k(n);
    vector<int> a(n);
    vector<vector<pair<int, int>>> km(n);
    for(int i = 0; i < n; i++){
        cin >> k[i] >> a[i];
    }
    cout << '\n';
    for(int i = 0; i < n; i++){
        km[k[i] - 1].emplace_back(a[i], i);
    }
    vector<vector<int>> bestLeft(n);
    vector<vector<int>> bestRight(n);
    int x = -1, y = -1, z = -1, w = -1;
    for(int i = 0; i < n; i++){
        if(x == -1){
            x = i;
        } else if(k[i] == k[x]){
            if(a[i] > a[x]) x = i;
        } else if (y == -1){
            if(a[i] < a[x]) {
                y = i;
            } else {
                y = x;
                x = i;
            }
        } else if(k[i] == k[y]){
            if(a[i] > a[y]) y = i;
        } else if(z == -1){
            if(a[i] < a[y]) {
                z = i;
            } else if(a[i] < a[x]) {
                z = y;
                y = i;
            } else {
                z = y;
                y = x;
                x = i;
            }
        } else if(k[i] == k[z]){
            if(a[i] > a[z]) z = i;
        } else if (w == -1){
            if(a[i] < a[z]) {
                w = i;
            } else if(a[i] < a[y]) {
                w = z;
                z = i;
            } else if(a[i] < a[x]) {
                w = z;
                z = y;
                y = i;
            } else {
                w = z;
                z = y;
                y = x;
                x = i;
            }
        } else if(k[i] == k[w]){
            if(a[i] > a[w]) w = i;
        } else if(a[i] < a[w]){
        } else if (a[i] < a[z]) {
            w = i;
        } else if(a[i] < a[y]) {
            w = z;
            z = i;
        } else if(a[i] < a[x]) {
            w = z;
            z = y;
            y = i;
        } else {
            w = z;
            z = y;
            y = x;
            x = i;
        }
        cout << "At i = " << i << " x y z w is " << x << ' ' << y << ' ' << z << ' ' << w << '\n';
        if(i < 2 || i >= n - 2) continue;
        if(x > -1 && k[x] == k[i]){
            bestLeft[i] = {y, z, w};
        } else if(y > -1 && k[y] == k[i]){
            bestLeft[i] = {x, z, w};
        } else if(z > -1 && k[z] == k[i]){
            bestLeft[i] = {x, y, w};
        } else {
            bestLeft[i] = {x, y, z};
        }
    }
    cout << '\n';
    x = -1, y = -1, z = -1, w = -1;
    for(int i = n - 1; i > 0; i--){
        if(x == -1){
            x = i;
        } else if(k[i] == k[x]){
            if(a[i] > a[x]) x = i;
        } else if (y == -1){
            if(a[i] < a[x]) {
                y = i;
            } else {
                y = x;
                x = i;
            }
        } else if(k[i] == k[y]){
            if(a[i] > a[y]) y = i;
        } else if(z == -1){
            if(a[i] < a[y]) {
                z = i;
            } else if(a[i] < a[x]) {
                z = y;
                y = i;
            } else {
                z = y;
                y = x;
                x = i;
            }
        } else if(k[i] == k[z]){
            if(a[i] > a[z]) z = i;
        } else if (w == -1){
            if(a[i] < a[z]) {
                w = i;
            } else if(a[i] < a[y]) {
                w = z;
                z = i;
            } else if(a[i] < a[x]) {
                w = z;
                z = y;
                y = i;
            } else {
                w = z;
                z = y;
                y = x;
                x = i;
            }
        } else if(k[i] == k[w]){
            if(a[i] > a[w]) w = i;
        } else if(a[i] < a[w]){
        } else if (a[i] < a[z]) {
            w = i;
        } else if(a[i] < a[y]) {
            w = z;
            z = i;
        } else if(a[i] < a[x]) {
            w = z;
            z = y;
            y = i;
        } else {
            w = z;
            z = y;
            y = x;
            x = i;
        }
        cout << "At i = " << i << " x y z w is " << x << ' ' << y << ' ' << z << ' ' << w << '\n';
        if(i < 2 || i >= n - 2) continue;
        if(x > -1 && k[x] == k[i]){
            bestRight[i] = {y, z, w};
        } else if(y > -1 && k[y] == k[i]){
            bestRight[i] = {x, z, w};
        } else if(z > -1 && k[z] == k[i]){
            bestRight[i] = {x, y, w};
        } else {
            bestRight[i] = {x, y, z};
        }
    }
    for(int i = 2; i < n - 2; i++){
        cout << "for " << i << ": " << bestLeft[i][0] << ", " << bestLeft[i][1] << ", " << bestLeft[i][2] << '\n';
    }
    cout << '\n';
    for(int i = n - 3; i >= 2; i--){
        cout << "for " << i << ": " << bestRight[i][0] << ", " << bestRight[i][1] << ", " << bestRight[i][2] << '\n';
    }
    cout << '\n';
    // for(int i = 2; i < n - 3; i++){
    //     for(int j = i + 1; j < n - 2; j++){
    //         cout << i << ' ' << j << '\n';
    //     }
    // }
    return 0;
}