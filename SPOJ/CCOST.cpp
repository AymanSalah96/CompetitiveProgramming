/*
Author: Ayman Salah
Category: Geometry
Idea:
- My approach is to maximize the lower left and minimize the upper right corners on all rectangles.
- If the new corners can make a valid rectangle then the answer will be the area of that rectangle.
- Otherwise the answer is zero (there is no common area).
*/

#define _CRT_SECURE_NO_WARNINGS
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
#include <hash_map>
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
#define sz(v) v.size()
#define ndl puts("")
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(3);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


const int MAX = (1 << 24);

ll BIT[MAX];

ll get(int idx) {
	if (idx < 0) return -1;
	++idx;
	ll res = 0;
	while (idx) {
		res += BIT[idx - 1];
		idx -= (idx & -idx);
	}
	return res;
}


void add(int idx, int val) {
	++idx;
	while (idx <= MAX) {
		BIT[idx - 1] += val;
		idx += (idx & -idx);
	}
}

enum T { BOTTOM, TREE, TOP };

struct Event {
	int y;
	T t;
	union {
		struct {
			int l, r, idx;
		};
		struct {
			int x, price;
		};
	};
} events[MAX];


int sorted[MAX];
ll res[MAX];
int t, n, x, y, p, r, e;
int xmin, ymin, xmax, ymax;

void clear() {
	memset(BIT, 0, sizeof BIT);
	memset(res, 0, sizeof res);
}

int main() {
	PLAY();

	cin >> t;
	while (t--) {
		clear();
		cin >> n;
		e = n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> p;
			events[i] = { y, TREE, x, p };
		}
		cin >> r;
		for (int i = 0; i < r; i++) {
			cin >> xmin >> ymin >> xmax >> ymax;
			events[e++] = { ymin, BOTTOM, xmin, xmax, i };
			events[e++] = { ymax, TOP, xmin, xmax, i };
		}
		iota(sorted, sorted + e, 0);
		sort(sorted, sorted + e, [](int a, int b) {
			return make_pair(events[a].y, events[a].t) <
				make_pair(events[b].y, events[b].t);
		});
		for (int i = 0; i < e; i++) {
			Event &e = events[sorted[i]];
			switch (e.t) {
			case BOTTOM:
				res[e.idx] -= get(e.r) - get(e.l - 1);
				break;
			case TOP:
				res[e.idx] += get(e.r) - get(e.l - 1);
				break;
			case TREE:
				add(e.x, e.price);
				break;
			}
		}
		for (int i = 0; i < r; i++)
			cout << res[i] << "\n";
	}

	return 0;
}
