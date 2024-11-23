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



int main() {
	freopen("cube.in", "r", stdin);
	freopen("cube.out", "w", stdout);
	int T = read();
	while (T--) {
		int n = read();
		ll sum1 = 0;
		vint a(n); for (int &i : a) i = read(), sum1 += i;
		a.insert(a.begin(), n);
		a.insert(a.end(), 0);
		for (int i = 1; i <= n; ++i) if (a[i] > a[i - 1]) a[i] = a[i - 1];
		int j = n + 1;
		for (int i = 1; i <= n; ++i) {
			if (a[i] > a[i - 1]) a[i] = a[i - 1];
			while (a[j - 1] < i) j--;
			if (j <= a[i]) a[i] = j - 1;
			else a[a[i] + 1] = min(i, a[a[i] + 1]), j = a[i] + 1; 
		}
		for (int i = 1; i <= n; ++i) sum1 -= a[i];
		cout << sum1 << '\n';
	}
	return 0;
}

