/*
Author: Ayman Salah

Category: Geometry

Idea:
- First of all find common point of the two adjacent sides (common_x, common_y).
- It's obvious that the fourth point equal to (x_1 + x_2 - common_x, y_1 + y_2 - common_y).
- (x_1, y_1) and (x_2, y_2) are the non-common points.
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
	double x, y;
	bool operator==(const point &p) const {
		return p.x == x && p.y == y;
	}
};

int main() {
	PLAY();
	
	point p1, p2, p3, p4;
	while (cin >> p1.x >> p1.y
		>> p2.x >> p2.y
		>> p3.x >> p3.y
		>> p4.x >> p4.y) {

		point ans;

		if (p1 == p3) // common point is p1, other points are p2 and p4
			ans = { (p2.x + p4.x) - p1.x, (p2.y + p4.y) - p1.y };
		else if (p1 == p4) // common point is p1, other points are p2 and p3
			ans = { (p2.x + p3.x) - p1.x, (p2.y + p3.y) - p1.y };
		else if (p2 == p3) // common point is p2, other points are p1 and p4
			ans = { (p1.x + p4.x) - p2.x, (p1.y + p4.y) - p2.y };
		else if (p2 == p4) // common point is p2, other points are p1 and p3
			ans = { (p1.x + p3.x) - p2.x, (p1.y + p3.y) - p2.y };

		cout << ans.x << " " << ans.y << endl;

	}
	return 0;
}
