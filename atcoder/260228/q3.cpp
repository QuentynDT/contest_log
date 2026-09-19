#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    const int m = s.size(), n = t.size();
    int i = 0, j = 0, count, ans = 0;
    while(i < m && j < n){
        count = 0;
        while(i < m && s[i] == 'A'){
            count++;
            i++;
        }
        while(j < n && t[j] == 'A'){
            count--;
            j++;
        }
        if(i >= m && j >= n){
            ans += abs(count);
            break;
        }
        if(i >= m || j >= n || s[i] != t[j]){
            cout << "-1\n";
            return 0;
        }
        ans += abs(count);
        i++;
        j++;
    }
    count = 0;
    while(i < m){
        if(s[i++] != 'A'){
            cout << "-1\n";
            return 0;
        }
        count++;
    }
    while(j < n){
        if(t[j++] != 'A'){
            cout << "-1\n";
            return 0;
        }
        count++;
    }
    ans += count;
    cout << ans << '\n';
    return 0;
}