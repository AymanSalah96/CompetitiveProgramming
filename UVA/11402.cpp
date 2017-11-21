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

int tree[11100005];
int lazy[11100005];
string s;

void build(int cur, int l, int r) {
	if (l == r) {
		tree[cur] = s[l] - '0';
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	tree[cur] = tree[left] + tree[right];
}

int flip(int x) {
	if (x == 1) return 2;
	if (x == 2) return 1;
	if (x == 3) return 0;
	return 3;
}

void propagate(int cur, int l, int r) {
	if (!lazy[cur]) return;
	int left = cur * 2;
	int right = cur * 2 + 1;
	if (lazy[cur] == 1)
		tree[cur] = (r - l + 1);
	else if (lazy[cur] == 2)
		tree[cur] = 0;
	else if (lazy[cur] == 3)
		tree[cur] = (r - l + 1) - tree[cur];

	if (l != r) {
		if (lazy[cur] == 1 || lazy[cur] == 2)
			lazy[left] = lazy[right] = lazy[cur];
		else
			lazy[left] = flip(lazy[left]),
			lazy[right] =  flip(lazy[right]);
	}
	lazy[cur] = 0;
}

void update(int cur, int l, int r, int x, int y, int val) {
	propagate(cur, l, r);
	if (l > y || r < x)  return;
	if (l >= x && r <= y) {
		lazy[cur] = val;
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

int solve(int cur, int l, int r, int x, int y) {
	if (l > y || r < x) return 0;
	propagate(cur, l, r);
	if (l >= x && r <= y) return tree[cur];
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	return solve(left, l, mid, x, y) + solve(right, mid + 1, r, x, y);
}

int main() {
	PLAY();


	int t;
	cin >> t;
	int test = 1;
	while (t--) {
		memset(tree, 0, sizeof tree);
		memset(lazy, 0, sizeof lazy);
		cout << "Case " << test++ << ":\n";
		int m; cin >> m;
		s = "0";
		while (m--) {
			int x; cin >> x;
			string tmp; cin >> tmp;
			while (x--) s += tmp;
		}
		int n = sz(s) - 1;
		build(1, 1, n);
		int q; cin >> q;
		int qnum = 1;
		while (q--) {
			char type;
			int x, y;
			cin >> type >> x >> y;
			x++; y++;
			if (type == 'F')
				update(1, 1, n, x, y, 1);
			else if (type == 'E')
				update(1, 1, n, x, y, 2);
			else if (type == 'I')
				update(1, 1, n, x, y, 3);
			else
				cout << "Q" << qnum++ << ": " << solve(1, 1, n, x, y) << endl;
		}
	}

	return 0;
}
