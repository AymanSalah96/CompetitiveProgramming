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

struct node {
	ll sum;
	ll pre, suf, mid;
	ll mx;
	node() {
		sum = pre = suf = mid = mx = INT_MIN;
	}
	node(int st) {
		sum = pre = suf = mid = mx = st;
	}

};

node tree[11000000];
int a[50005];


void merge(int cur, int left, int right) {
	tree[cur].sum = tree[left].sum + tree[right].sum;
	tree[cur].pre = max(tree[left].pre, tree[left].sum + tree[right].pre);
	tree[cur].suf = max(tree[right].suf, tree[left].suf + tree[right].sum);
	tree[cur].mid = tree[left].suf + tree[right].pre;
	tree[cur].mx = max({
		tree[cur].sum,
		tree[cur].pre,
		tree[cur].suf,
		tree[cur].mid,
		tree[left].mx,
		tree[right].mx
	});
}

void build(int cur, int l, int r) {
	if (l == r) {
		tree[cur] = node(a[l]);
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	merge(cur, left, right);
}

node query(int cur, int l, int r, int x, int y) {
	if (l > y || r < x) return node(INT_MIN);
	if (l >= x && r <= y) return tree[cur];
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	node ln = query(left, l, mid, x, y);
	node rn = query(right, mid + 1, r, x, y);
	node nn;
	nn.sum = ln.sum + rn.sum;
	nn.pre = max(ln.pre, ln.sum + rn.pre);
	nn.suf = max(rn.suf, ln.suf + rn.sum);
	nn.mid = ln.suf + rn.pre;
	nn.mx = max({
		nn.mx,
		nn.mid,
		nn.pre,
		nn.suf,
		nn.sum,
		ln.mx,
		rn.mx
	});
	return nn;
}

int main() {
	PLAY();

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(1, 1, n, l, r).mx << "\n";
	}

	return 0;
}
