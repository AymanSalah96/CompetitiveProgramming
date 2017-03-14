/*
Author: Ayman Salah

Category: Geometry

Idea:
- My approach is to brute force on all pairs of points
- then check every other point if it lie on the same line with them or not.
- maximize current answer with the number of points that lie on the same line.
- It's obvious that the minimum answer is only one point.
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

struct point {
	int x, y;
};

bool sameLine(point p1, point p2, point p3) {
	return (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) == 0;
}

point p[705];

int main() {
	PLAY();
	
	int t;
	cin >> t;
	string line;
	getline(cin, line);
	cin.ignore();
	while (t--) {
		int idx = 0;
		while (getline(cin, line) && line != "") {
			SS ss(line);
			ss >> p[idx].x >> p[idx].y;
			idx++;
		}
		int n = idx;
		int res = 1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int cnt = 2;
				for (int k = j + 1; k < n; k++)
					cnt += sameLine(p[i], p[j], p[k]);
				res = max(res, cnt);
			}
		}
		cout << res << endl;
		if (t >= 1)	cout << endl;
	}

	return 0;
}
