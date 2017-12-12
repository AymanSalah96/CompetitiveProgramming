/*
Author: Ayman Salah

Category: Geometry, Brute Force

Idea:
- Take each 4 pointes make all possible rotations and minimize on the number of moves you have made.
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

#define PI acos(-1.0)
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

struct P {
	ll x, y;
};

P home[4];
P pos[4];

P rotate(int idx, int cnt) {
	P p = pos[idx];
	while (cnt--) {
		int dx = p.x - home[idx].x;
		int dy = p.y - home[idx].y;
		p.x = home[idx].x - dy;
		p.y = home[idx].y + dx;
	}
	return p;
}

ll dist(P p1, P p2) {
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

bool valid(P p1, P p2, P p3, P p4) {
	vector<ll> d;
	d.push_back(dist(p1, p2));
	d.push_back(dist(p1, p3));
	d.push_back(dist(p1, p4));
	d.push_back(dist(p2, p3));
	d.push_back(dist(p2, p4));
	d.push_back(dist(p3, p4));
	sortva(d);
	if (d[sz(d) - 1] != d[sz(d) - 2]) return false;
	for (int i = 0; i < 4; i++)
		if (d[i] != d[0]) return false;
	if (d[0] * 2 != d.back()) return false;
	return d[0] > 0;
}

int main() {
	PLAY();

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < 4; j++)
			cin >> pos[j].x >> pos[j].y >> home[j].x >> home[j].y;
	
		int res = INT_MAX;
	
		for (int a = 0; a < 4; a++) {
			P p1 = rotate(0, a);
			for (int b = 0; b < 4; b++) {
				P p2 = rotate(1, b);
				for (int c = 0; c < 4; c++) {
					P p3 = rotate(2, c);
					for (int d = 0; d < 4; d++) {
						P p4 = rotate(3, d);
						if (valid(p1, p2, p3, p4))
							res = min(res, a + b + c + d);
					}
				}
			}
		}
		
		if (res == INT_MAX) res = -1;
		cout << res << endl;
	}

	
	return 0;
}
