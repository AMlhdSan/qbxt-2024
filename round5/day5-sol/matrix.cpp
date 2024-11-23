#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;

const ll LINF = (ll)1e18;

int a[65][65], b[65], c[65];
int n, m;

namespace RS
{
	ll dp[2][1 << 20];

	void solve()
	{
		vector<vector<bool>> par(n + 1, vector<bool>(1 << m));

		for (int mask = 0; mask < (1 << m); mask++)
		{
			dp[0][mask] = dp[1][mask] = -LINF;
		}

		dp[0][0] = 0;

		for (int i = 0; i < n; i++)
		{
			int cm = 0;

			for (int j = 0; j < m; j++)
			{
				cm ^= (a[j][i] << j);
			}

			for (int mask = 0; mask < (1 << m); mask++)
			{
				int prv_mask = (mask ^ cm);

				if (dp[0][mask] > dp[0][prv_mask] + c[i])
				{
					dp[1][mask] = dp[0][mask];
					par[i][mask] = false;
				}
				else
				{
					dp[1][mask] = dp[0][prv_mask] + c[i];
					par[i][mask] = true;
				}
			}

			for (int mask = 0; mask < (1 << m); mask++)
			{
				dp[0][mask] = dp[1][mask];
				dp[1][mask] = -LINF;
			}
		}

		int req_mask = 0;

		for (int i = 0; i < m; i++)
		{
			req_mask += (b[i] << i);
		}

		ll ans = dp[0][req_mask];

		if (ans < 0)
		{
			cout << "-1\n";
			return;
		}

		cout << ans << '\n';
		vector<int> vec(n);

		for (int i = n - 1, j = req_mask; ~i; i--)
		{
			int cm = 0;
			for (int j = 0; j < m; j++)
			{
				cm ^= (a[j][i] << j);
			}
			vec[i] = par[i][req_mask];
			if (vec[i])
				req_mask ^= cm;
		}

		for (int i = 0; i < n; i++)
		{
			cout << vec[i] << " \n"[i == n - 1];
		}
	}
}

namespace LS
{
	bool bit(int x, int p)
	{
		return x & (1 << p);
	}

	int lhs[65], rhs[65];

	void solve()
	{
		int L = n / 2, R = n - L;
		ll req = 0;

		for (int i = 0; i < m; i++)
		{
			if (b[i])
			{
				req ^= (1ll << i);
			}

			for (int j = 0; j < n; j++)
			{
				if (a[i][j])
				{
					if (j < L)
					{
						lhs[i] += (1 << j);
					}
					else
					{
						rhs[i] += (1 << (j - L));
					}
				}
			}
		}

		unordered_map<ll, pair<ll, int>> best;

		for (int mask = 0; mask < (1 << L); mask++)
		{
			ll cm = 0, sum = 0;

			for (int i = 0; i < L; i++)
			{
				if (bit(mask, i))
				{
					sum += c[i];
				}
			}

			for (int i = 0; i < m; i++)
			{
				int cur = __builtin_popcount(lhs[i] & mask);

				if (cur % 2)
				{
					cm ^= (1ll << i);
				}
			}

			best[cm] = max(best[cm], {sum, mask});
		}

		tuple<ll, int, int> ans(-LINF, -1, -1);

		for (int mask = 0; mask < (1 << R); mask++)
		{
			ll cm = 0, sum = 0;

			for (int i = 0; i < R; i++)
			{
				if (bit(mask, i))
				{
					sum += c[L + i];
				}
			}

			for (int i = 0; i < m; i++)
			{
				int cur = __builtin_popcount(rhs[i] & mask);

				if (cur % 2)
				{
					cm ^= (1ll << i);
				}
			}

			auto it = best.find(req ^ cm);

			if (it != best.end())
			{
				pair<ll, int> P = it->second;
				ans = max(ans, make_tuple(P.first + sum, P.second, mask));
			}
		}

		ll cost = get<0>(ans);
		int x = get<1>(ans);
		int y = get<2>(ans);

		if (cost < 0)
		{
			cout << "-1\n";
			return;
		}

		cout << cost << '\n';

		for (int i = 0; i < L; i++)
		{
			cout << bit(x, i) << ' ';
		}

		for (int i = 0; i < R; i++)
		{
			cout << bit(y, i) << " \n"[i == R - 1];
		}
	}
}

void Main()
{
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  memset(c, 0, sizeof c);
  memset(RS::dp, 0, sizeof RS::dp);
  memset(LS::lhs, 0, sizeof LS::lhs);
  memset(LS::rhs, 0, sizeof LS::rhs);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}

		
	}
  for (int i = 0; i < m; ++i) cin >> b[i];

	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}

	if (m <= 20)
	{
		RS::solve();
	}
	else
	{
		LS::solve();
	}

}

int main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
  int T;
  for (std::cin >> T; T; --T) {
    int N, M;
    std::cin >> N >> M;
    m = N; n = M;
    Main();
  }
}
