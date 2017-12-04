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

const int MOD = 1e9 + 7;
priority_queue<ll> qu1, qu2;

void update(ll val) {
	if (val <= qu1.top())
		qu1.push(val);
	else
		qu2.push(-val);
	int size = sz(qu1) + sz(qu2);
	if (size % 2 == 0) {
		while (sz(qu1) > sz(qu2)) {
			qu2.push(-qu1.top());
			qu1.pop();
		}
		while (sz(qu1) < sz(qu2)) {
			qu1.push(-qu2.top());
			qu2.pop();
		}
	}
	else {
		while (sz(qu1) <= sz(qu2)) {
			qu1.push(-qu2.top());
			qu2.pop();
		}
	}
}

int main() {
	PLAY();

	int t;
	cin >> t;
	while (t--) {
		priority_queue<ll> tmp1,tmp2;
		swap(tmp1, qu1);
		swap(tmp2, qu2);
		ll a, b, c, n;
		cin >> a >> b >> c >> n;
		qu1.push(1);
		ll res = 1;
		for (int i = 2; i <= n; i++) {
			ll median = qu1.top();
			ll cur = (a * median + b * i + c) % MOD;
			res += cur;
			update(cur);
		}
		cout << res << "\n";
	}

	return 0;
}
