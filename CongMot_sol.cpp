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

const int N = 2e5 + 10;
vector<int> dp(N, 0);

void process() {
  for (int i = 0; i < 9; i++) {
    dp[i] = 2;
  }
  dp[9] = 3;
  for (int i = 10; i < N; i++) {
    dp[i] = dp[i - 9] + dp[i - 10];
    dp[i] %= mod;
  }
}

void solve() {
  Matrix a(10, 10);
  a[8][0] = a[9][0] = 1;
  a[8][9] = 1;
  for (int i = 0; i < 9; i++) {
    a[i][i + 1] = 1;
  }
  Matrix base = Matrix({{3, 2, 2, 2, 2, 2, 2, 2, 2, 2}});
  int n, k;
  cin >> n >> k;
  int n1 = n;
  int ans = 0;
  while (n > 0) {
    int x = n % 10;
    int p = k - (10 - x);
    if (p < 0) ans += 1;
    else if (p <= 9) {
      ans += dp[p];
    }
    else {
      Matrix ret = base * a.pow(p - 9);
      ans += ret[0][0];
    }
    ans %= mod;
    n /= 10;
  }
  int ans2 = 0;
  while (n1 > 0) {
    int x = n1 % 10;
    int p = k - (10 - x);
    if (p < 0) ans2 += 1;
    else ans2 += dp[p];
    ans2 %= mod;
    n1 /= 10;
  }
  cout << ans << '\n';
  // cout << ans2 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  process();
  int cas = 1;
  // cin >> cas;
  while (cas--) solve();
  return 0;
}