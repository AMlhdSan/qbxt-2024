#include <bits/stdc++.h>
#define il inline
#define re register
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
#define N 500005
#define M 19
int n, m, q, v[N], L[N], R[N];
int id[N], mx[N * 4], tg[N * 4]; vector<int> Q[N];
struct node {int op, a, b, c;} a[N];
il void build(int i, int l, int r) {
  tg[i] = 0; if(l == r) {mx[i] = v[l]; return ;} int mid = l + r >> 1;
  build(i << 1, l, mid), build(i << 1 | 1, mid + 1, r), mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
}
il void psd(int i, int w) {mx[i] = max(mx[i], w), tg[i] = max(tg[i], w);}
il void pus(int i) {psd(i << 1, tg[i]), psd(i << 1 | 1, tg[i]), tg[i] = 0;}
il void add(int el, int er, int w, int i = 1, int l = 1, int r = n) {
  if(l >= el && r <= er) {mx[i] = tg[i] = w; return ;} int mid = l + r >> 1; pus(i);
  if(mid >= el) add(el, er, w, i << 1, l, mid); if(mid < er) add(el, er, w, i << 1 | 1, mid + 1, r);
  mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
}
il void mod(int el, int er, int v, int i = 1, int l = 1, int r = n) {
  if(mx[i] < v) return ;
  if(l == r) {mx[i] %= v; return ;} int mid = l + r >> 1;
  if(mid >= el) mod(el, er, v, i << 1, l, mid); if(mid < er) mod(el, er, v, i << 1 | 1, mid + 1, r); 
  mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
}
il int query(int el, int er, int i = 1, int l = 1, int r = n) {
  if(l >= el && r <= er) return mx[i]; int mid = l + r >> 1, ns = 0; pus(i);
  if(mid >= el) ns = max(ns, query(el, er, i << 1, l, mid)); if(mid < er) ns = max(ns, query(el, er, i << 1 | 1, mid + 1, r));
  return ns;
}
int pr[N][M], nx[N][M];
int main() {
  freopen("hope.in", "r", stdin);
  freopen("hope.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(re int i = 1; i <= n; ++i) cin >> v[i];
  for(re int i = 1; i <= m; ++i) cin >> L[i] >> R[i];
  cin >> q;
  for(re int i = 1; i <= q; ++i) {
    cin >> a[i].op >> a[i].a >> a[i].b;
    if(a[i].op > 2) cin >> a[i].c;
    if(a[i].op == 4) Q[a[i].b].eb(i);
    // cerr << i << " " << a[i].op << "\n";
  }
  for(re int i = 1; i <= m; ++i) {
    pr[i][0] = query(L[i], L[i]), nx[i][0] = query(R[i], R[i]), add(L[i], R[i], i);
    for(auto t : Q[i]) id[t] = query(a[t].c, a[t].c);
  }
  for(re int j = 1; j < M; ++j)
    for(re int i = 1; i <= m; ++i)
      pr[i][j] = pr[pr[i][j - 1]][j - 1], nx[i][j] = nx[nx[i][j - 1]][j - 1];
  build(1, 1, n);
  for(re int i = 1; i <= q; ++i) {
    // cerr << i << " " << q << " " << a[i].op << "\n";
    if(a[i].op == 1) {
      int x = a[i].a, y = a[i].b;
      v[x] = query(x, x), v[y] = query(y, y);
      add(x, x, v[y]), add(y, y, v[x]), swap(v[x], v[y]); continue;
    }
    if(a[i].op == 2) {add(a[i].a, a[i].a, a[i].b), v[a[i].a] = a[i].b; continue;}
    if(a[i].op == 3) {
      int l = a[i].a, r = a[i].b, v = a[i].c;
      mod(l, r, v); continue;
    }
    // cout << i << " ";
    if(id[i] < a[i].a) {cout << (v[a[i].c] = query(a[i].c, a[i].c)) << "\n"; continue;}
    int l = id[i], r = id[i], t = a[i].a;
    for(re int i = M - 1; i >= 0; --i) {
      if(pr[l][i] >= t) l = pr[l][i];
      if(nx[r][i] >= t) r = nx[r][i];
    }
    cout << query(L[l], R[r]) << "\n";
  }
}