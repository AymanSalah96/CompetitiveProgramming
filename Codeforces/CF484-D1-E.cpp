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

const int MAX = (1 << 21);
struct node;
node *roots[MAX];
int a[MAX], ori[MAX];
map<int, int> mp;
vector<pair<int, int>> v;
node *empty;

struct data {
	int maxOnes;
	int preOnes;
	int sufOnes;
	data() {
		maxOnes = 0;
		preOnes = 0;
		sufOnes = 0;
	}
	data(int mx, int pre, int suf) {
		maxOnes = mx;
		preOnes = pre;
		sufOnes = suf;
	}
};

struct node {
	data d;
	node *lft, *rit;
	node() {
		lft = rit = this;
		d = data();
	}
	node(data nw, node *l = empty, node *r = empty) {
		lft = l; rit = r;
		d = nw;
	}
};

data merge(data l, data r, int x, int y) {
	int lft_size = (x + y) / 2 - x + 1;
	int rit_size = (y - x + 1) - lft_size;
	int maxOnes = max({ l.maxOnes, r.maxOnes, l.sufOnes + r.preOnes });
	int preOnes = l.preOnes + (l.preOnes == lft_size ? r.preOnes : 0);
	int sufOnes = r.sufOnes + (r.sufOnes == rit_size ? l.sufOnes : 0);
	return data(maxOnes, preOnes, sufOnes);
}

node* insert(node *cur, int l, int r, int idx) {
	if (idx < l || idx > r) return cur;
	if (l == r) return new node(data(1, 1, 1));
	int mid = (l + r) / 2;
	node *lft = insert(cur->lft, l, mid, idx);
	node *rit = insert(cur->rit, mid + 1, r, idx);
	return new node(merge(lft->d, rit->d, l, r), lft, rit);
}

data query(node *cur, int l, int r, int x, int y) {
	if (l > y || r < x) return data(0, 0, 0);
	if (l >= x && r <= y) return cur->d;
	int mid = (l + r) / 2;
	return merge(query(cur->lft, l, mid, x, y), query(cur->rit, mid + 1, r, x, y), l, r);
}


int main() {
	PLAY();

	empty = new node();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]];
	}
	int cnt = 0;
	for (auto &e : mp) {
		ori[cnt] = e.first;
		e.second = cnt++;
	}

	v.resize(n);

	for (int i = 0; i < n; i++)
		v[i] = { mp[a[i]], i };

	sortvd(v);
	
	roots[v[0].first] = empty;
	roots[v[0].first] = insert(roots[v[0].first], 0, n, v[0].second);

	for (int i = 1; i < n; i++) {
		int idx = v[i].second;
		roots[v[i].first] = insert(roots[v[i - 1].first], 0, n, v[i].second);
	}
	
	int q;
	cin >> q;
	while (q--) {
		int l, r, w;
		cin >> l >> r >> w;
		l--; r--;
		int lo = 0, hi = cnt - 1, res = 0;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (query(roots[mid], 0, n, l, r).maxOnes >= w) {
				lo = mid + 1;
				res = mid;
			}
			else hi = mid - 1;
		}
		cout << ori[res] << "\n";
	}
	
	return 0;
}
