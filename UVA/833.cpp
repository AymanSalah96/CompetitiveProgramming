/*
Author: Ayman Salah

Category: Geometry

Idea:
- For every source point keep getting the first line sigment below this point untill you reach the last one from bottom.
- Always the water will fall from the lower value of y axis intersecting with x coordinate of the line segment.
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
	cout << fixed << setprecision(4);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const double EPS = 1e-8;

struct point {
	int x, y;
};

struct line {
	point p1, p2;
};

bool can(int x, line l) {
	return (x >= l.p1.x && x <= l.p2.x) || (x >= l.p2.x && x <= l.p1.x);
}
#define inRange(c, l, r) ((c >= l && c <= r) || (c >= r && c <= l))
int main() {
	PLAY();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<line> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].p1.x >> v[i].p1.y >> v[i].p2.x >> v[i].p2.y;
		int q;
		cin >> q;
		while (q--) {
			point p;
			cin >> p.x >> p.y;
			int res = p.x, y = p.y;
			while (true){
				int j = -1;
				double mx = INT_MIN;
				for (int i = 0; i < n; i++) {
					if (can(res, v[i])) {
						double tmp = v[i].p2.y + 1.0*(v[i].p1.y - v[i].p2.y)*(res - v[i].p2.x) / (v[i].p1.x - v[i].p2.x);
						if (tmp < y && tmp > mx) {
							mx = tmp;
							j = i;
						}
					}
				}
				if (j != -1) {
					if (1.0*(v[j].p1.y - v[j].p2.y) / (v[j].p1.x - v[j].p2.x) <= EPS)
						res = max(v[j].p1.x, v[j].p2.x);
					else
						res = min(v[j].p1.x, v[j].p2.x);
					y = min(v[j].p1.y, v[j].p2.y);
				}
				else break;
			}
			cout << res << endl;
		}
		if (t) cout << endl;
	}

	return 0;
}
