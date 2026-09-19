#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Using a high value for infinity that won't overflow during addition
const long long INF = 4e18; 

struct Matrix {
    int sz;
    vector<vector<long long>> mat;

    Matrix(int n) : sz(n), mat(n, vector<long long>(n, INF)) {}

    // Redefining multiplication for the (min, +) semiring
    Matrix operator*(const Matrix& other) const {
        Matrix res(sz);
        for (int k = 0; k < sz; k++) {
            for (int i = 0; i < sz; i++) {
                if (mat[i][k] == INF) continue;
                for (int j = 0; j < sz; j++) {
                    if (other.mat[k][j] == INF) continue;
                    res.mat[i][j] = min(res.mat[i][j], mat[i][k] + other.mat[k][j]);
                }
            }
        }
        return res;
    }
};

/**
 * Standard Binary Exponentiation (Binary Lifting)
 * Time Complexity: O(N^3 * log K)
 */
Matrix power(Matrix a, long long k) {
    Matrix res(a.sz);
    // Identity matrix for (min, +) is 0 on diagonals and INF elsewhere
    for (int i = 0; i < a.sz; i++) res.mat[i][i] = 0;

    while (k > 0) {
        if (k & 1) res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    Matrix base(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> base.mat[i][j];
        }
    }
    Matrix result = power(base, k);
    for (int i = 0; i < n; i++) {
        cout << result.mat[i][i] << "\n";
    }

    return 0;
}