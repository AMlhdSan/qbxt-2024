#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef vector<vint> vvint;

int read() {
	int a = 0, b = 0; char c = getchar();
	while (c < '0' || c > '9') b ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9') a = a * 10 - 48 + c, c = getchar();
	return b ? -a : a;
}

const int N = 1000005, K = 1005, mod = 1000000007;

vint p;
int is[K];
int dp[N];
vint kn[K], ki[K];
int ans[N];
void Add(int &a, int b) { if ((a += b) >= mod) a -= mod; }

int main() {
	freopen("myself.in", "r", stdin);
	freopen("myself.out", "w", stdout);
	for (int i = 2; i < K; ++i) {
		if (!is[i]) p.push_back(i);
		for (int j : p) {
			if (i * j >= K) break;
			is[i * j] = 1;
			if (i % j == 0) break;
		}
	}
	p.push_back(N);
	fill(dp, dp + N, 1);
	int T = read();
	for (int i = 0; i < T; ++i) {
		int n = read(), k = read();
		kn[k].push_back(n);
		ki[k].push_back(i);
	}
	int i = 0;
	for (int k = 2; k < K; ++k) {
		if (p[i] < k) {
			int r = p[i];
			for (int j = r; j < N; ++j) Add(dp[j], dp[j - r]);
			++i;
		}
		for (int j = 0; j < kn[k].size(); ++j) ans[ki[k][j]] = (dp[kn[k][j]] + 1) % mod;
	}
	for (int i = 0; i < T; ++i) cout << ans[i] << '\n';
	
	return 0;
}

