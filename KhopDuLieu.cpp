#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

typedef long long ll;
 
class Segtree{
public:
  vector<ll> ST;
  vector<ll> a;
  int N;
  Segtree(int n) {
    N = n, n++;
    a.resize(n);
    ST.resize(4 * n);
  }
 
  ll merge(ll x, ll y) {
    return __gcd(x, y);
  }
 
  void build(int id, int l, int r) {
    if (l == r) {
      ST[id] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    ST[id] = merge(ST[id * 2], ST[id * 2 + 1]);
  }
 
  void update(int id, int l, int r, int u, int v, ll val) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
      ST[id] += val;
      return;
    }
    int m = (l + r) / 2;
    update(id * 2, l, m, u, v, val);
    update(id * 2 + 1, m + 1, r, u, v, val);
    ST[id] = merge(ST[id * 2], ST[id * 2 + 1]);
  }
 
  ll get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) {
      return ST[id];
    }
    int m = (l + r) / 2;
    return merge(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
  }
  void update(int u, int v, ll val) { update(1, 1, N, u, v, val);}
  ll get(int u, int v) { return get(1, 1, N, u, v); }
};
 


void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1, 0), b(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  Segtree st(n);
  for (int i = 1; i <= n; i++) {
    st.a[i] = abs(a[i] - b[i]);
  }
  st.build(1, 1, n);
  while (k--) {
    int l, r;
    cin >> l >> r;
    cout << st.get(l, r) << '\n';
  }
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