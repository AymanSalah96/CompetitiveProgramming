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

pair<int, int> tree[11000000];
int lazy[11000000];
int a[100005];

void build(int cur, int l, int r) {
	if (l == r) {
		tree[cur] = { a[l], l };
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	if (tree[left].first <= tree[right].first)
		tree[cur] = tree[left];
	else
		tree[cur] = tree[right];
}

void propagate(int cur, int l, int r) {
	if (!lazy[cur]) return;
	tree[cur].first += lazy[cur];
	if (l != r) {
		int left = cur * 2;
		int right = cur * 2 + 1;
		lazy[left] += lazy[cur];
		lazy[right] += lazy[cur];
	}
	lazy[cur] = 0;
}

pair<int, int> query(int cur, int l, int r, int x, int y) {
	propagate(cur, l, r);
	if (l > y || r < x) return{ INT_MAX, -1 };
	if (l >= x && r <= y) return tree[cur];
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	pair<int, int> lf = query(left, l, mid, x, y);
	pair<int, int> rg = query(right, mid + 1, r, x, y);
	if (lf.first <= rg.first)
		return lf;
	return rg;
}

void update(int cur, int l, int r, int x, int y) {
	propagate(cur, l, r);
	if (l > y || r < x) return;
	if (l >= x && r <= y) {
		lazy[cur]++;
		propagate(cur, l, r);
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	update(left, l, mid, x, y);
	update(right, mid + 1, r, x, y);
	if (tree[left].first <= tree[right].first)
		tree[cur] = tree[left];
	else
		tree[cur] = tree[right];
}

int main() {
	PLAY();

	for (int i = 0; i < 11000000; i++)
		tree[i] = { INT_MAX, -1 };

	int n, m, w;
	cin >> n >> m >> w;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);

	while (m--) {
		int idx = query(1, 1, n, 1, n).second;
		update(1, 1, n, idx, min(n, idx + w - 1));
	}
	cout << query(1, 1, n, 1, n).first << endl;

	return 0;
}
