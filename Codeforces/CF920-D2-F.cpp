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

ll tree[4 * 300005];
int a[300005];
int cnt[1000005];

set<pair<int, int>> st;

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

void update(int cur, int l, int r, int idx) {
	if (l == r) {
		tree[cur] = a[idx];
		return;
	}
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	if (idx <= mid)
		update(left, l, mid, idx);
	else
		update(right, mid + 1, r, idx);
	tree[cur] = tree[left] + tree[right];
}

ll sum_query(int cur, int l, int r, int x, int y) {
	if (l > y || r < x) return 0;
	if (l >= x && r <= y) return tree[cur];
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	return sum_query(left, l, mid, x, y) + sum_query(right, mid + 1, r, x, y);
}

int main() {
	PLAY();

	for (int i = 1; i <= 1e6; i++)
		for (int j = i; j <= 1e6; j += i)
			cnt[j]++;

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 2)
			st.insert({ i, a[i] });
	}

	build(1, 1, n);

	set<pair<int, int>>::iterator it;

	while (m--) {
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 1) {
			it = st.lower_bound(make_pair(l, -1));
			while (it != st.end() && it->first <= r) {
				int idx = it->first;
				a[idx] = cnt[a[idx]];
				update(1, 1, n, idx);
				st.erase(it);
				it = st.lower_bound(make_pair(idx, -1));
				if (a[idx] > 2)
					st.insert({ idx, a[idx] });
			}
		}
		else
			cout << sum_query(1, 1, n, l, r) << "\n";
	}

	return 0;
}
