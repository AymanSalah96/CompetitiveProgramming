#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
using namespace std;

#define PI 3.14159265359
#define all(v) v.begin(),v.end()
#define sortva(v) sort(all(v))
#define sortvd(v) sort(v.rbegin(),v.rend())
#define sortaa(a,n) sort(a,a+n)
#define sortad(a,n) sort(a,a+n),reverse(a,a+n)
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1,v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define sfstr(v) scanf("%s", v);
#define sz(v) (int)v.size()
#define ndl puts("")
#define flush fflush(stdout)
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


int l[100005], r[100005];

void update(int x, int y) {
	l[y] = x;
	r[x] = y;
}

int main() {
	PLAY();

	int n, m;
	int test = 1;
	while (cin >> n >> m) {
		cout << "Case " << test++ << ": ";
		for (int i = 1; i <= n; i++)
			l[i] = i - 1, r[i] = i + 1;
		r[0] = 1, l[0] = n, r[n] = 0;
		bool rev = false;
		while (m--) {
			int op; cin >> op;
			if (op == 4) {
				rev = !rev;
			}
			else {
				int x, y;
				cin >> x >> y;
				if (op == 3) {
					if (r[y] == x) swap(x, y);
					if (r[x] == y) {
						update(l[x], y);
						update(x, r[y]);
						update(y, x);
					}
					else {
						int tmpl = l[y];
						int tmpr = r[y];
						update(l[x], y);
						update(y, r[x]);
						update(tmpl, x);
						update(x, tmpr);
					}
				}
				else {
					if (rev) op = 3 - op;
					if ((op == 1 && l[y] == x) || (op == 2 && r[y] == x))
						continue;
					if (op == 1) {
						update(l[x], r[x]);
						update(l[y], x);
						update(x, y);
					}
					else {
						update(l[x], r[x]);
						update(x, r[y]);
						update(y, x);
					}
				}
			}
		}
		ll res = 0;
		for (int i = 1, p = r[0]; i <= n; i++, p = r[p])
			if (i % 2) res += p;

		if (rev && n % 2 == 0)
			res = (ll)n*(n + 1) / 2 - res;
	
		cout << res << endl;
	}

	return 0;
}
