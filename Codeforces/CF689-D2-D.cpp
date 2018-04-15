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
#include <assert.h>
using namespace std;

#define PI 3.14159265359
#define all(v) v.begin(),v.end()
#define sortva(v) sort(all(v))
#define sortvd(v) sort(v.rbegin(),v.rend())
#define sortaa(first,n) sort(first,first+n)
#define sortad(first,n) sort(first,first+n),reverse(first,first+n)
#define sfi1(v) scanf("%dist",&v)
#define sfi2(v1,v2) scanf("%dist %dist",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%dist %dist %dist",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define sfstr(v) scanf("%sum", v);
#define sz(v) (int)v.size()
#define ndl puts("")
#define flush fflush(stdout)
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int di[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dj[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll first, ll second) { return !second ? first : gcd(second, first % second); }
ll lcm(ll first, ll second) { return (first / gcd(first, second)) * second; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(5);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int MAX = 2e5 + 10;
const int MAXLOG = 18;

int a[MAX], b[MAX];
int tableMax[MAX][MAXLOG], tableMin[MAX][MAXLOG];
int n, lg2[MAX];

void build() {
	for (int i = 2; i <= n; i++)
		lg2[i] = lg2[i >> 1] + 1;

	for (int i = 0; i < n; i++) {
		tableMax[i][0] = a[i];
		tableMin[i][0] = b[i];
	}

	for (int k = 1; k < MAXLOG; k++) {
		int b = (1 << (k - 1));
		int mx = 2 * b - 1;
		for (int i = 0; i + mx < n; i++) {
			tableMax[i][k] = max(tableMax[i][k - 1], tableMax[i + b][k - 1]);
			tableMin[i][k] = min(tableMin[i][k - 1], tableMin[i + b][k - 1]);
		}
	}
}

int query(int l, int r, int type) {
	int k = lg2[r - l + 1];
	if (type)
		return max(tableMax[l][k], tableMax[r - (1 << k) + 1][k]);
	else
		return min(tableMin[l][k], tableMin[r - (1 << k) + 1][k]);
}

int getMaxR(int l) {
	int lo = l, hi = n - 1, res = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int mx = query(l, mid, 1);
		int mn = query(l, mid, 0);
		if (mx <= mn) {
			if (mn == mx) res = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	return res;
}

int getMinR(int l, int maxR) {
	int lo = l, hi = maxR, res = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int mx = query(l, mid, 1);
		int mn = query(l, mid, 0);
		if (mn <= mx) {
			if (mn == mx) res = mid;
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}
	return res;

}

int main() {
	PLAY();
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < n; i++)
		cin >> b[i];

	build();
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int maxR = getMaxR(i);
		if (maxR == -1) continue;
		int minR = getMinR(i, maxR);
		if (minR == -1) continue;
		res += maxR - minR + 1;
	}
	cout << res << endl;

	return 0;
}
