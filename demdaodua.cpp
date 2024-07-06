#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define FOR(i,a,b) for(int i=(a),_b=(b); i <= _b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i >= _b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)
using namespace std;

const long long MOD = 1000000007LL;

int n, t, a[55];

struct Matrix {
    long long x[55][55];

    Matrix operator * (Matrix a) const {
        Matrix res;
        FOR(i,1,n) FOR(j,1,n) {
            res.x[i][j] = 0;
            FOR(k,1,n) {
                res.x[i][j] = (res.x[i][j] + x[i][k] * a.x[k][j]) % (MOD-1);
            }
        }
        return res;
    }

    void print() {
        FOR(i,1,n) {
            FOR(j,1,n) cout << x[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
    }
} I, A, P;

void init() {
    memset(I.x, 0, sizeof I.x);
    memset(A.x, 0, sizeof A.x);

    FOR(i,1,n) I.x[i][i] = 1;
    FOR(i,1,n-1) A.x[i][i+1] = 1;
    FOR(i,1,n) A.x[n][i] = 1;
}

Matrix lt(int t) {
    P = I;
    REP(i,30) {
        if (t & (1<<i)) {
            P = P * A;
            // P.print();
        }
        A = A * A;
    }
    return P;
}

long long power(long long x, long long k) {
    if (k == 0) return 1 % MOD;
    if (k == 1) return x % MOD;
    long long mid = power(x, k >> 1);
    mid = (mid * mid) % MOD;
    if (k & 1) return mid * x % MOD;
    else return mid;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    scanf("%d%d", &t, &n);
    FOR(i,1,n) scanf("%d", &a[i]);
    init();
    P = lt(t-n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << P.x[i][j] << ' ';
        }
        cout << '\n';
    }
    long long res = 1;
    FOR(i,1,n) {
        res = res * power(a[i], P.x[n][i]) % MOD;
    }
    cout << res << endl;
}
