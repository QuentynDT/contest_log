#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<int> freq(26);
    for(char& c : s){
        freq[c - 'a']++;
    }
    const int mx = ranges::max(freq);
    for(char& c : s){
        if(freq[c - 'a'] != mx) cout << c;
    }
    cout << '\n';
    return 0;
}