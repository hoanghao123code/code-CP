#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

const int mod = 1e9 + 7;

struct Matrix {
  vector<vector<int>> mt;
  int row() const {
    return mt.size();
  }
  int col() const {
    return mt[0].size();
  }
  auto & operator [] (int i) {
    return mt[i];
  }
  const auto & operator[] (int i) const { return mt[i]; }
  Matrix() {};
  Matrix(int r, int c) : mt(r, vector<int>(c)) {};
  Matrix (const vector<vector<int>> &d) : mt(d) {};
  Matrix identity(long long n) {
    Matrix a = Matrix(n, n);
    for (int i = 0; i < n; i++) {
      a[i][i] = 1;
    }
    return a;
  }
  Matrix operator * (const Matrix &b) {
    Matrix a = *this;
    assert(a.col() == b.row());
    Matrix c = Matrix(a.row(), b.col());
    for (int i = 0; i < a.row(); i++) {
      for (int j = 0; j < b.col(); j++) {
        for (int k = 0; k < a.col(); k++) {
          c[i][j] = ((c[i][j] % mod) +  ((a[i][k] % mod) * (b[k][j] % mod)) % mod) % mod;
          c[i][j] %= mod;
        }
      }
    }
    return c;
  }
  Matrix pow(long long exp) {
    assert(row() == col());
    Matrix base = *this;
    Matrix ans = identity(row());
    for (; exp > 0; exp >>= 1, base = base * base) {
      if (exp & 1) {
        ans = ans * base;
      }
    }
    return ans;
  }
};

void solve() {
  Matrix a = Matrix({{1, 1, 0},
                     {1, 0, 1},
                     {1, 0, 0}});
  Matrix ans = Matrix({{4, 2, 1}});
  int k;
  cin >> k;
  if (k == 1) {
    return void(cout << 1 << '\n');
  }
  if (k == 2) {
    return void(cout << 2 << '\n');
  }
  if (k == 3) {
    return void(cout << 4 << '\n');
  }
  Matrix ret = ans * a.pow(k - 3);
  cout << ret[0][0] % mod << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int cas = 1;
  // cin >> cas;
  while (cas--) solve();
  return 0;
}