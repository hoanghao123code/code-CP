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
  // int n;
  // cin >> n;
  // dp[i][0] là số lượng chuỗi sẽ làm Limak vui
  // dp[i][1] là số lượng chuỗi sẽ làm Limak buồn
  // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
  // dp[0][0] = 1;
  // dp[0][1] = 0;
  // for (int i = 1; i <= n; i++) {
  //   dp[i][0] = dp[i - 1][0] * 19 + dp[i - 1][1] * 6;
  //   dp[i][1] = dp[i - 1][0] * 7 + dp[i - 1][1] * 20;
  // }
  // f[i] là số chuỗi độ dài i làm Limak vui
  // g[i] là số chuỗi độ dài i làm Limak buồn
  // vector<int> f(n + 1, 0), g(n + 1, 0);
  // f[0] = 1, g[0] = 0;
  // for (int i = 1; i <= n; i++) {
  //   f[i] = f[i - 1] * 19 + g[i - 1] * 6;
  //   g[i] = f[i - 1] * 7 + g[i - 1] * 20;
  // } 
  // cout << f[n] << '\n';
  Matrix a = Matrix({{19, 7},
                      {6, 20}});
  Matrix ans = Matrix({{1, 0}});

  int k;
  cin >> k;
  Matrix ret = ans * a.pow(k);
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