#include <bits/stdc++.h>
#define il inline
#define re register
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int, int>
using namespace std;
#define N 2000005
il void chkmin(int &x, int y) {(x > y) && (x = y);}
int n, R, S, X, E[N], C[N];
int cnt, bic[N], und[N], oud[N], tran[N];
vector<pii> g[N];
struct node {int y; ll l, T;} ;
vector<node> spec[N];
int v[N], l[N], inid[N], outid[N];
ll f[N]; bool vis[N];
struct PQ {
  int x; ll w;
  il bool operator < (const PQ &t) const {return w > t.w;}
} ;
il ll up(ll x, ll y) {
  return (x + y - 1) / y;
}
il ll calc(ll l, ll t, ll f) {
  if(l > f) l = l - up(l - f, t) * t;
  return l + up(f - l, t) * t;
}
il void dijkstra() {
  for(re int i = 1; i <= cnt; ++i) f[i] = 1e18;
  priority_queue<PQ> Q; Q.emplace(PQ {1, f[1] = 0});
  while(!Q.empty()) {
    int x = Q.top().x; Q.pop();
    if(vis[x]) continue; vis[x] = 1;
    for(auto t : g[x]) {
      int y = t.fi, w = t.se;
      if(f[y] > f[x] + w)
        f[y] = f[x] + w, Q.emplace(PQ {y, f[y]});
    }
    for(auto t : spec[x]) {
      int y = t.y; ll nf = calc(t.l, t.T, f[x]);
      if(f[y] > nf) f[y] = nf, Q.emplace(PQ {y, f[y]});
    }
  }
}
int main() {
  freopen("capital.in", "r", stdin);
  freopen("capital.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> R >> S >> X;
  for(re int i = 1; i <= n; ++i) cin >> E[i];
  for(re int i = 1; i <= n; ++i) cin >> C[i];
  cnt = n;
  for(re int i = 1; i <= n; ++i) bic[i] = ++cnt; // 上单车
  for(re int i = 1; i <= n; ++i) tran[i] = ++cnt; // 换乘中转点
  for(re int i = 1; i <= n; ++i) {
    g[i].eb(bic[i], X), g[bic[i]].eb(i, 0); // 上下单车
    g[i].eb(tran[i], E[i]); // 进地铁
    g[tran[i]].eb(i, E[i]); // 出地铁
  }
  while(R--) {
    int x, y, w; cin >> x >> y >> w;
    g[bic[x]].eb(bic[y], w);
    g[bic[y]].eb(bic[x], w);
    // 单车路线
  }
  while(S--) {
    int k; ll T; cin >> k;
    for(re int i = 0; i < k; ++i) cin >> v[i] >> l[i]; cin >> v[k] >> T;
    if(v[0] != v[k]) { // 非环线
      for(re int i = 0; i <= k; ++i) inid[i] = ++cnt;
      for(re int i = k - 1; i > 0; --i) outid[i] = ++cnt;
      outid[0] = inid[0], outid[k] = inid[k];
      ll now = 0;
      for(re int i = 0; i <= k; ++i) {
        spec[und[v[i]]].eb(node {inid[i], now, T}); // 上车
        g[inid[i]].eb(v[i], E[v[i]]); // 出地铁
        spec[tran[v[i]]].eb(node {inid[i], now, T}); // 换乘
        g[inid[i]].eb(tran[v[i]], C[v[i]]);
        if(i < k) now += l[i];
      }
      for(re int i = k - 1; i > 0; --i) {
        if(i < k) now += l[i];
        spec[und[v[i]]].eb(node {outid[i], now, T}); // 上车
        g[outid[i]].eb(v[i], E[v[i]]); // 出地铁
        spec[tran[v[i]]].eb(node {outid[i], now, T}); // 换乘
        g[outid[i]].eb(tran[v[i]], C[v[i]]);
      }
      for(re int i = 0; i < k; ++i) g[inid[i]].eb(inid[i + 1], l[i]); // 开往下一站
      for(re int i = k - 1; i >= 0; --i) g[outid[i + 1]].eb(outid[i], l[i]); // 回程
    }
    else { // 环线
      for(re int i = 0; i < k; ++i) inid[i] = ++cnt;
      for(re int i = k - 1; i > 0; --i) outid[i] = ++cnt;
      outid[k] = inid[k] = outid[0] = inid[0];
      ll now = 0;
      for(re int i = 0; i < k; ++i) {
        spec[und[v[i]]].eb(node {inid[i], now, T}); // 上车
        g[inid[i]].eb(v[i], E[v[i]]); // 出地铁
        spec[tran[v[i]]].eb(node {inid[i], now, T}); // 换乘
        g[inid[i]].eb(tran[v[i]], C[v[i]]);
        if(i < k) now += l[i];
      }
      now = 0;
      for(re int i = k - 1; i > 0; --i) {
        if(i < k) now += l[i];
        spec[und[v[i]]].eb(node {outid[i], now, T}); // 上车
        g[outid[i]].eb(v[i], E[v[i]]); // 出地铁
        spec[tran[v[i]]].eb(node {outid[i], now, T}); // 换乘
        g[outid[i]].eb(tran[v[i]], C[v[i]]);
      }
      for(re int i = 0; i < k; ++i) g[inid[i]].eb(inid[i + 1], l[i]); // 开往下一站
      for(re int i = k - 1; i >= 0; --i) g[outid[i + 1]].eb(outid[i], l[i]); // 回程
    }
  }
  dijkstra();
  for(re int i = 1; i <= n; ++i) cout << f[i] << " ";
  return 0;
}