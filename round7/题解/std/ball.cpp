#include <bits/stdc++.h>
#define db long double
#define il inline
#define re register
#define ui unsigned
#define ll long long
#define ull unsigned ll
#define pii pair<int, int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
#define N 100005
int n, k;
struct node {
  int x, v;
  il bool operator < (const node &t) const {
    return x < t.x;
  }
} a[N];
db stk[N];
il bool check(db mid) {
  int m = 0; stk[0] = -1e20;
  for(re int i = 1; i <= n; ++i) {
    db now = a[i].x + mid * a[i].v; if(stk[m] < now) stk[++m] = now;
    else stk[lower_bound(stk + 1, stk + 1 + m, now) - stk] = now;
  }
//   cerr << mid << " " << n - m << "\n";
  return n - m <= k;
}
int main() {
  freopen("ball.in", "r", stdin);
  freopen("ball.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for(re int i = 1; i <= n; ++i)
    cin >> a[i].x >> a[i].v;
  sort(a + 1, a + 1 + n);
  db l = 0, r = 2e9;
  for(re int T = 0; T <= 50; ++T) {
    db mid = (l + r) * 0.5;
    if(check(mid)) l = mid; else r = mid;
  }
  if(check(l + 1)) cout << "Forever";
  else printf("%.4Lf", l);
  cerr << 1.0 * clock() / CLOCKS_PER_SEC;
}