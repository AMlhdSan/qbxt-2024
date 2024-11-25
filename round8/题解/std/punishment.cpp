#include <bits/stdc++.h>
#define il inline
#define re register
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
#define N 1000005
#define P 998244353
il void addr(int &x, int y) {(x += y) >= P && (x -= P);}
int n, K, c[N]; bool vis[N];
ll f[N][2]; int g[N][2];
vector<int> G[N];
il void DFS(int x, int fa) {
  vector<int> son; for(auto y : G[x]) if(y != fa) son.eb(y), DFS(y, x);
  if(son.empty()) {f[x][0] = c[x], g[x][0] = g[x][1] = 1; return ;} int m = son.size();
  ll s = 0; for(auto y : son) s += f[y][0]; f[x][1] = 1e18;
  for(auto y : son) f[x][1] = min(f[x][1], s - f[y][0] + f[y][1]);
  f[x][0] = min(s, f[x][1] + c[x]); vector<int> pre(m), suf(m);
  pre[0] = g[son[0]][0]; for(re int i = 1; i < m; ++i) pre[i] = 1ll * pre[i - 1] * g[son[i]][0] % P;
  suf[m - 1] = g[son[m - 1]][0]; for(re int i = m - 2; i >= 0; --i) suf[i] = 1ll * suf[i + 1] * g[son[i]][0] % P;
  if(f[x][0] == s) addr(g[x][0], pre[m - 1]);
  for(re int i = 0; i < m; ++i)
    if(f[x][1] == s - f[son[i]][0] + f[son[i]][1]) {
      ll v = 1ll * (i ? pre[i - 1] : 1) * (i + 1 < m ? suf[i + 1] : 1) % P * g[son[i]][1] % P;
      addr(g[x][1], v); if(f[x][0] == f[x][1] + c[x]) addr(g[x][0], v);
    }
}
bool trans[N][2];
il void DP(int x, int fa) {
  if(f[x][0] == f[x][1] + c[x] && trans[x][0]) vis[x] = 1;
  vector<int> son; for(auto y : G[x]) if(y != fa) son.eb(y);
  if(son.empty()) return ; int m = son.size();
  ll s = 0; for(auto y : son) s += f[y][0];
  if(f[x][0] == s) for(auto y : son) trans[y][0] |= trans[x][0];
  int cnt = 0, id = -1;
  bool ext = ((f[x][0] == f[x][1] + c[x]) & trans[x][0]) | trans[x][1];
  for(re int i = 0; i < m; ++i)
    if(f[x][1] == s - f[son[i]][0] + f[son[i]][1])
      ++cnt, id = son[i], trans[son[i]][1] |= ext;
  if(cnt > 1) for(auto y : son) trans[y][0] |= ext;
  else for(auto y : son) if(y != id) trans[y][0] |= ext;
  for(auto y : son) DP(y, x);
}
int main() {
  freopen("punishment.in", "r", stdin);
  freopen("punishment.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for(re int i = 1; i <= n; ++i) cin >> c[i];
  for(re int i = 1, x, y; i < n; ++i) cin >> x >> y, G[x].eb(y), G[y].eb(x);
  cin >> K;
  DFS(1, 0), trans[1][0] = 1, DP(1, 0);
  if(K >= 1) cout << f[1][0] << "\n";
  if(K >= 2) {for(re int i = 1; i <= n; ++i) if(vis[i]) cout << i << " "; cout << "\n";}
  if(K >= 3) cout << g[1][0];
}