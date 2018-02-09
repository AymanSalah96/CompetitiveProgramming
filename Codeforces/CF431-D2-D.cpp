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


ll nCr[70][70];

ll get(ll x, ll k) {
	if (k == 0) return x == 0;
	if (x == 0) return 0;
	ll mx = 0;
	while (1ll << (mx + 1) <= x) mx++;
	return nCr[mx][k] + get(x - (1ll << mx), k - 1);
}

int main() {
	PLAY();


	nCr[0][0] = 1;
	for (int i = 1; i < 70; i++) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; j++)
			nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
	}

	ll m, k;
	cin >> m >> k;
	ll lo = 1, hi = 1e18;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll cnt = get(mid * 2, k) - get(mid, k);
		if (cnt == m) {
			cout << mid << endl;
			return 0;
		}
		if (cnt > m)
			hi = mid - 1;
		else
			lo = mid + 1;
	}

	return 0;
}
