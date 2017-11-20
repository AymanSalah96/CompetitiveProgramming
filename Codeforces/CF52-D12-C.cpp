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

struct SegmentTree{

	vector<ll> tree;
	vector<ll> lazy;
	SegmentTree(int n) {
		tree.resize(2 * n);
		lazy.resize(2 * n);
		for (int i = 0; i < sz(tree); i++)
			tree[i] = 1e18, lazy[i] = 0;
	}

	void propagate(int cur, int l, int r, int x, int y) {
		if (lazy[cur]) {
			tree[cur] += lazy[cur];
			if (l != r)
				lazy[x] += lazy[cur], lazy[y] += lazy[cur];
			lazy[cur] = 0;
		}
	}
	void build(int cur, int l, int r, vector<ll>& arr) {
		if (l == r) {
			tree[cur] = arr[l];
			return;
		}
		int left = 2 * cur;
		int right = 2 * cur + 1;
		int mid = (l + r) / 2;
		build(left, l, mid, arr);
		build(right, mid + 1, r, arr);
		tree[cur] = min(tree[left], tree[right]);
	}

	void update(int cur, int l, int r, int x, int y, ll val) {
		int left = 2 * cur;
		int right = 2 * cur + 1;
		int mid = (l + r) / 2;
		propagate(cur, l, r, left, right);
		if (l > y || r < x)	return;
		if (l >= x && r <= y) {
			tree[cur] += val;
			if (l != r)
				lazy[left] += val, lazy[right] += val;
			return;
		}
		update(left, l, mid, x, y, val);
		update(right, mid + 1, r, x, y, val);
		tree[cur] = min(tree[left], tree[right]);
	}
	ll solve(int cur, int l, int r, int x, int y) {
		int left = 2 * cur;
		int right = 2 * cur + 1;
		int mid = (l + r) / 2;
		propagate(cur, l, r, left, right);

		if (x > r || y < l)
			return 1e18;
		if (l >= x && r <= y)
			return tree[cur];
		return min(solve(left, l, mid, x, y), solve(right, mid + 1, r, x, y));
	}
};

int main() {
	PLAY();

	int n;
	cin >> n;
	vector<ll> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	SegmentTree segTree = SegmentTree(1 << 21);
	segTree.build(1, 1, n, v);
	int m;
	cin >> m;
	cin.ignore();
	while (m--) {
		int a[3];
		string s;
		getline(cin, s);
		SS ss(s);
		int i = 0;
		while (ss >> a[i++]);
		a[0]++, a[1]++;
		if (i == 3) {
			if (a[0] <= a[1])
				cout << segTree.solve(1, 1, n, a[0], a[1]) << endl;
			else
				cout << min(segTree.solve(1, 1, n, a[0], n),
					segTree.solve(1, 1, n, 1, a[1])) << endl;
		}
		else  {
			if (a[0] <= a[1])
				segTree.update(1, 1, n, a[0], a[1], a[2]);
			else {
				segTree.update(1, 1, n, a[0], n, a[2]);
				segTree.update(1, 1, n, 1, a[1], a[2]);
			}
		}
	}

	return 0;
}
