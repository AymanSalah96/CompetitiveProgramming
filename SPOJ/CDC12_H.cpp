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

ll tree[1100005];
ll lazy[1100005];

void update(int cur, int l, int r, int x, int y){
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	if (lazy[cur]) {
		tree[cur] += (r - l + 1) * lazy[cur];
		if (l != r)
			lazy[left] += lazy[cur], lazy[right] += lazy[cur];
		lazy[cur] = 0;
	}
	if (l > y || r < x) return;
	if (l >= x && r <= y) {
		tree[cur] += (r - l + 1);
		if (l != r) lazy[left]++, lazy[right]++;
		return;
	}
	update(left, l, mid, x, y);
	update(right, mid + 1, r, x, y);
	tree[cur] = tree[left] + tree[right];
}

ll solve(int cur, int l, int r, int x, int y){
	if (l > y || r < x) return 0;
	int left = cur * 2;
	int right = cur * 2 + 1;
	int mid = (l + r) / 2;
	if (lazy[cur]) {
		tree[cur] += (r - l + 1) * lazy[cur];
		if (l != r)
			lazy[left] += lazy[cur], lazy[right] += lazy[cur];
		lazy[cur] = 0;
	}
	if (l >= x && r <= y) return tree[cur];
	return solve(left, l, mid, x, y) + solve(right, mid + 1, r, x, y);
}

int main() {
	PLAY();

	int t;
	cin >> t;
	int test = 1;
	while (t--) {
		cout << "Scenario #" << test++ << ":" << endl;
		int n, q;
		cin >> n >> q;
		memset(tree, 0, sizeof tree);
		memset(lazy, 0, sizeof lazy);
		while (q--) {
			string quest;
			int x, y;
			cin >> quest >> x >> y;
			if (quest[0] == 'm') {
				update(1, 1, n, x, y);
				cout << "OK" << endl;
			}
			else
				cout << solve(1, 1, n, x, y) << endl;
		}
	}

	return 0;
}
