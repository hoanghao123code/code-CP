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
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  Matrix mt(k, k);
  for (int i = 0; i < k; i++) {
    mt[i][0] = 1;
  }
  for (int i = 0; i < k - 1; i++) {
    mt[i][i + 1] = 1;
  }
  // Matrix b = Matrix({{1, 1, 1}});
  Matrix ret = mt.pow(n - k);
  int ans = 1;
  reverse(a.begin(), a.end());
  // for (int i = 0; i < k; i++) {
  //   for (int j = 0; j < k; j++) {
  //     cout << ret[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
  for (int i = 0; i < k; i++) {
    ans = mul(ans, power(a[i], ret[i][0]));
    ans %= mod;
  }
  cout << ans << '\n';
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
