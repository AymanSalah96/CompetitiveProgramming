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

struct P{
	ll x, y;
};

ll dist(P p1, P p2) {
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int n;
P p[2], v[2005];

int main() {
	PLAY();

	cin >> n >> p[0].x >> p[0].y >> p[1].x >> p[1].y;

	vector<pair<ll, int>> r1(n), r2(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
		r1[i] = { dist(p[0], v[i]), i };
		r2[i] = { dist(p[1], v[i]), i };
	}
	sortva(r1);
	sortva(r2);
	
	ll res = LLONG_MAX;

	for (int i = 0; i < n; i++) {
		ll mx = 0;
		for (int j = 0; j < n; j++) {
			ll d = dist(p[1], v[r1[j].second]);
			if (dist(p[0], v[r1[j].second]) <= r1[i].first) continue;
			mx = max(mx, d);
		}
		res = min(res, r1[i].first + mx);
		mx = 0;
		for (int j = 0; j < n; j++) {
			ll d = dist(p[0], v[r2[j].second]);
			if (dist(p[1], v[r2[j].second]) <= r2[i].first) continue;
			mx = max(mx, d);
		}
		res = min(res, r2[i].first + mx);
	}

	cout << res << endl;
	return 0;
}
