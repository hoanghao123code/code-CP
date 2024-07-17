#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// #define int long long 
// #define fi first
// #define se second
typedef long long ll;
ll mn, mx;
ll mn_K, mx_K;

void solve() {
  ll n = rnd.next(mn, mx);
  ll k = rnd.next(mn_K, mx_K);
  cout << n << ' ' << k << '\n';
}

int32_t main(int argc , char* argv[]) {
  registerGen(argc, argv , 1);
  // argv[1] = "10", argv[2] = "20";
  // argv[3] = "8", argv[4] = "10";
  mn = stoll(argv[1]);
  mx = stoll(argv[2]);
  mn_K = stoll(argv[3]);
  mx_K = stoll(argv[4]);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int cas = 1;
  // cin >> cas;
  while (cas--) solve();
  return 0;
}