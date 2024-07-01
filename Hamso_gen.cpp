#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// #define int long long 
// #define fi first
// #define se second
typedef long long ll;
ll mn, mx;

void solve() {
  int a = rnd.next(1, 10);
  int b = rnd.next(1, 10);
  int c = rnd.next(1, 10);
  int d = rnd.next(1, 10);
  cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
  ll k = rnd.next(mn, mx);
  cout << k << '\n';
}

int32_t main(int argc , char* argv[]) {
  registerGen(argc, argv , 1);
  // argv[1] = "10", argv[2] = "20";
  mn = stoll(argv[1]);
  mx = stoll(argv[2]);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int cas = 1;
  // cin >> cas;
  while (cas--) solve();
  return 0;
}