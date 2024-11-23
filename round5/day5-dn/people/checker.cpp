#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vint;
typedef vector<vint> vvint;

const int N = 100005;
int n, k;
int c[N], l[N];

void pre() {
	n = inf.readInt(1, 100000), k = inf.readInt(3, 100000);
	for (int i = 0; i < n; ++i) c[i] = inf.readInt(0, k - 1), l[i] = inf.readInt(1, 1000000000);
}


void chk(InStream &ouf, const char* typ, int sc, ll m) {
	vvint ql(n);
	for (int i = 0; i < n; ++i) {
		int s = ouf.readInt(1, 3);
		for (int j = 0; j < s; ++j) ql[i].push_back(ouf.readInt(1, 1000000000));
	}
	vint cor;
	int s = ouf.readInt(0, 3 * n);
	while (s--) cor.push_back(ouf.readInt(1, 1000000000));
	
	
	vector< multiset<int> > kk(k);
	for (int i = 0; i < n; ++i) {
		ll sum = 0;
		for (int j : ql[i]) sum += j;
		if (sum != l[i]) quitp(20, "In the %d-th sequence, you give the division incorrectly", i);
		int cc = c[i];
		for (int j : ql[i]) {
			kk[cc].insert(j);
			cc = (cc + j) % k;
		}
	}
	ll sum = 0; for (int j : cor) sum += j;
	if (sum != m) quitp(20, "In the final sequence, you give the wrong length of the scheme");
	
	for (int j : cor) {
		auto p = kk[sc].find(j);
		if (p == kk[sc].end())
			quitp(20, "In the final sequence, the scheme you give has a subsegment that does not exist in your division of the given sequence");
		kk[sc].erase(p);
		sc = (sc + j) % k;
	}
}

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	pre();
	int c1 = ouf.readInt(0, k - 1), c2 = ans.readInt(0, k - 1);
	ll m = ouf.readLong(), jm = ans.readLong();
	if (m != jm) quitf(_wa, "length is different. answer = %lld, output = %lld", jm, m);
	chk(ouf, "output", c1, m);
	quitf(_ok, "All corrected. mobai!!!!111");
	
	return 0;
}
