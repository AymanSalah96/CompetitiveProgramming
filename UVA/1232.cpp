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


const int N = 100000;

int tree_max[4 * N + 10];
int tree_min[4 * N + 10];
int lazy[4 * N + 10];

void clear() {
	memset(tree_max, 0, sizeof tree_max);
	memset(tree_min, 0, sizeof tree_min);
	memset(lazy, 0, sizeof lazy);
}

void propagate(int cur, int l, int r) {
	if (!lazy[cur]) return;
	tree_max[cur] = lazy[cur];
	tree_min[cur] = lazy[cur];
	if (l != r) {
		int left = cur * 2;
		int right = cur * 2 + 1;
		lazy[left] = lazy[cur];
		lazy[right] = lazy[cur];
	}
	lazy[cur] = 0;
}

int solve(int cur, int l, int r, int x, int y, int val) {
	propagate(cur, l, r);
	if (l > y || r < x) return 0;
	if (l >= x && r <= y) {
		if (val >= tree_max[cur]) return r - l + 1;
		else if (val < tree_min[cur]) return 0;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	return solve(left, l, mid, x, y, val) + solve(right, mid + 1, r, x, y, val);
}

void update(int cur, int l, int r, int x, int y, int val) {
	propagate(cur, l, r);
	if (l > y || r < x) return;
	if (l >= x && r <= y) {
		if (val >= tree_max[cur]) {
			lazy[cur] = val;
			propagate(cur, l, r);
			return;
		}
		else if (val < tree_min[cur]) return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	update(left, l, mid, x, y, val);
	update(right, mid + 1, r, x, y, val);
	tree_max[cur] = max(tree_max[left], tree_max[right]);
	tree_min[cur] = min(tree_min[left], tree_min[right]);
}

int main() {
	PLAY();

	int t;
	cin >> t;
	while (t--) {
		clear();
		int n;
		cin >> n;
		ll res = 0;
		while (n--) {
			int l, r, v;
			cin >> l >> r >> v;
			res += solve(1, 1, N, l, r - 1, v);
			update(1, 1, N, l, r - 1, v);
		}
		cout << res << "\n";
	}


	return 0;
}
