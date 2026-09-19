#include <bits/stdc++.h>

using namespace std;

const vector<bool>& get_is_prime() {
    static const vector<bool> is_prime = []() {
        constexpr int limit = 10000000;
        vector<bool> prime(limit, true);
        prime[0] = false;
        prime[1] = false;

        for (int p = 2; p * p < limit; p++) {
            if (prime[p]) {
                for (int i = p * p; i < limit; i += p) {
                    prime[i] = false;
                }
            }
        }
        return prime;
    }();
    return is_prime;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;
    const int n = s.size();
    const vector<bool>& is_prime = get_is_prime();

    unordered_map<char, int> back;
    vector<char> front(10, '*');
    int num = 0;
    const int ps = is_prime.size();
    auto ground = [&](this auto self, int i) -> void {
        if (i == n) {
            if (num < ps && is_prime[num]) {
                cout << num << '\n';
                exit(0);
            }
            return;
        }

        if (back.contains(s[i])) {
            num = 10 * num + back.at(s[i]);
            self(i + 1);
            num /= 10;
        } else {
            for (int d = 0; d <= 9; d++) {
                if (i == 0 && d == 0) continue;
                if (front[d] == '*') {
                    front[d] = s[i];
                    back[s[i]] = d;
                    num = 10 * num + d;

                    self(i + 1);

                    num /= 10;
                    back.erase(s[i]);
                    front[d] = '*';
                }
            }
        }
    };

    ground(0);

    cout << "-1" << '\n';
    return 0;
}
