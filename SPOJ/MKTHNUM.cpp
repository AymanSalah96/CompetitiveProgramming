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

const int N = (1 << 17);

struct node;
node *empty;

struct node {
	int sum;
	node *lft, *rit;
	node() {
		lft = rit = this;
		sum = 0;
	}
	node(int s, node *l = empty, node *r = empty) {
		lft = l; rit = r; sum = s;
	}
};

node *insert(node *cur, int l, int r, int val) {
	if (val < l || val > r) return cur;
	if (l == r) return new node(cur->sum + 1);
	int mid = l + (r - l) / 2;
	node *lft = insert(cur->lft, l, mid, val);
	node *rit = insert(cur->rit, mid + 1, r, val);
	return new node(lft->sum + rit->sum, lft, rit);
}

int query(node *rit, node *lft, int k, int l, int r) {
	if (l == r) return l;
	int left_size = rit->lft->sum - lft->lft->sum;
	int mid = l + (r - l) / 2;
	if (k <= left_size)
		return query(rit->lft, lft->lft, k, l, mid);
	return query(rit->rit, lft->rit, k - left_size, mid + 1, r);
}

node *roots[N];

int main() {
	PLAY();

	empty = new node();
	roots[0] = empty;

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		roots[i] = insert(roots[i - 1], -1e9, 1e9, x);
	}
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << query(roots[r], roots[l - 1], k, -1e9, 1e9) << "\n";
	}
	
	return 0;
}
