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

ll a[100005];
ll tree[11000000];
ll lazy[11000000];

void build(int cur, int l, int r) {
	if (l == r) {
		tree[cur] = a[l];
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	tree[cur] = tree[left] + tree[right];
}

void propagate(int cur, int l, int r) {
	if (!lazy[cur]) return;
	tree[cur] += (r - l + 1) * lazy[cur];
	if (l != r) {
		int left = cur * 2;
		int right = cur * 2 + 1;
		lazy[left] += lazy[cur];
		lazy[right] += lazy[cur];
	}
	lazy[cur] = 0;
}

void update(int cur, int l, int r, int x, int y, int val) {
	propagate(cur, l, r);
	if (l > y || r < x)
		return;
	if (l >= x && r <= y) {
		lazy[cur] += val;
		propagate(cur, l, r);
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	update(left, l, mid, x, y, val);
	update(right, mid + 1, r, x, y, val);
	tree[cur] = tree[left] + tree[right];
}

ll query(int cur, int l, int r, int x, int y) {
	propagate(cur, l, r);
	if (l > y || r < x) return 0;
	if (l >= x && r <= y) return tree[cur];
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	return query(left, l, mid, x, y) +
		query(right, mid + 1, r, x, y);
} 

int main() {
	PLAY();

	int t;
	cin >> t;
	while (t--) {
		memset(tree, 0, sizeof tree);
		memset(lazy, 0, sizeof lazy);
		int n, c;
		cin >> n >> c;
		build(1, 1, n);
		while (c--) {
			int ty, p, q, v;
			cin >> ty >> p >> q;
			if (p > q) swap(p, q);
			if (ty == 0) {
				cin >> v;
				update(1, 1, n, p, q, v);
			}
			else
				cout << query(1, 1, n, p, q) << "\n";
		}
	}

	return 0;
}
