#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for(char& ch : s){
        if(ch == 'A') a++;
        else if(ch == 'B'){
            if(a > b) b++;
        } else if(ch == 'C'){
            if(a > 0 && b > 0){
                a--;
                b--;
                c++;
            }
        }
    }
    cout << c << '\n';
    return 0;
}