/*
Author: Ayman Salah

Category: segment tree with lazy propagation

Idea:
- type 0 query : update the current node with this value (r - l + 1) * x
- type 1 query : add to the current node this value (r - l + 1) * x * x + 2 * (old range sum)
- so we need to store in our tree two infos, first square range sum and the second is range sum
- you also will need to keep track of queries time to make sure you update the last query
*/

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

ll tree_sum[1100000];
ll tree_square_sum[1100000];
pair<int, int> lazy1[1100000];
pair<int, int> lazy2[1100000];
ll a[100005];
int cur_time;

void build(int cur, int l, int r) {
	if (l == r) {
		tree_sum[cur] = a[l];
		tree_square_sum[cur] = a[l] * a[l];
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	tree_sum[cur] = tree_sum[left] + tree_sum[right];
	tree_square_sum[cur] = tree_square_sum[left] + tree_square_sum[right];
}

void propagate(int cur, int l, int r) {
	if (lazy1[cur].second == 0 && lazy2[cur].second == 0) return;
	if (lazy1[cur].second > lazy2[cur].second) { // add lazy1[cur].first
		tree_square_sum[cur] += (r - l + 1) * (lazy1[cur].first * lazy1[cur].first) + 2 * lazy1[cur].first * tree_sum[cur];
		tree_sum[cur] += (r - l + 1) * lazy1[cur].first;
		if (l != r) {
			int left = cur * 2;
			int right = cur * 2 + 1;
			lazy1[left].first += lazy1[cur].first;
			lazy1[right].first += lazy1[cur].first;
		}
		lazy1[cur] = { 0, 0 };
	}
	else { // set all values lazy2[cur].first
		tree_sum[cur] = (r - l + 1) * lazy2[cur].first;
		tree_square_sum[cur] = (r - l + 1) * lazy2[cur].first * lazy2[cur].first;
		if (l != r) {
			int left = cur * 2;
			int right = cur * 2 + 1;
			lazy2[left].first = lazy2[cur].first;
			lazy2[right].first = lazy2[cur].first;
		}
		lazy2[cur] = { 0, 0 };
	}
}

ll query(int cur, int l, int r, int x, int y) {
	propagate(cur, l, r);
	if (l > y || r < x) return 0;
	if (l >= x && r <= y) return tree_square_sum[cur];
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	return query(left, l, mid, x, y) + query(right, mid + 1, r, x, y);
}

void update(int cur, int l, int r, int x, int y, int val, bool type) {
	propagate(cur, l, r);
	if (l > y || r < x) return;
	if (l >= x && r <= y) {
		if (type == 0)
			lazy1[cur] = { val, cur_time };
		else
			lazy2[cur] = { val, cur_time };
		propagate(cur, l, r);
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	update(left, l, mid, x, y, val, type);
	update(right, mid + 1, r, x, y, val, type);
	tree_sum[cur] = tree_sum[left] + tree_sum[right];
	tree_square_sum[cur] = tree_square_sum[left] + tree_square_sum[right];
}

int main() {
	PLAY();

	int t;
	cin >> t;
	int test = 1;
	while (t--) {
		cout << "Case " << test++ << ":\n";
		cur_time = 0;
		int n, q;
		cin >> n >> q;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		build(1, 1, n);
		while (q--) {
			cur_time++;
			int type, l, r, x;
			cin >> type >> l >> r;
			if (type == 2)
				cout << query(1, 1, n, l, r) << "\n";
			else if (type == 1) {
				cin >> x;
				update(1, 1, n, l, r, x, 0);
			}
			else {
				cin >> x;
				update(1, 1, n, l, r, x, 1);
			}
		}
	}
	
	return 0;
}
