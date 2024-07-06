#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

// const int mod = 4294967296;
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
          c[i][j] = ((c[i][j] % (mod - 1)) +  ((a[i][k] % (mod - 1)) * (b[k][j] % (mod - 1))) % (mod - 1)) % (mod - 1);
          c[i][j] %= (mod - 1);
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



int mul(int a, int b) {
  return ((a % mod) * (b % mod)) % mod;
}

int power(int a, int b) {
  int ans = 1;
  for (; b > 0; b >>= 1, a = mul(a, a)) {
    if (b & 1) {
      ans = mul(ans, a);
    }
  }
  return ans;
}

void solve() {
  int k;
  cin >> k;
  Matrix a(65, 65);
  a[64][64] = 1;
  for (int i = 0; i < 64; i++) {
    a[i][64] = 1;
    for (int j = 0; j < 64; j++) {
      int r1 = i / 8, c1 = i % 8;
      int r2 = j / 8, c2 = j % 8;
      int dist_r = abs(r1 - r2);
      int dist_c = abs(c1 - c2);
      if (dist_r == 2 && dist_c == 1 || dist_r == 1 && dist_c == 2) {
        a[i][j] = 1;
      }
    }
  }
  Matrix ret = a.pow(k + 1);
  cout << ret[0][64] << '\n';
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
