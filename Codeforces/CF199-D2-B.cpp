/*
Author: Ayman Salah

Category: geometry

Idea:
- get the distance between the two rings
- for every circle check if it intersect with the other ring or not
- it's clear that the answer will be not more than 4
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

struct R {
	int x, y;
	int r, R1;
};

struct C{
	int x, y, r;
};

R ring[2];

ld dist(R r1, R r2) {
	return sqrt((r1.x - r2.x)*(r1.x - r2.x) + (r1.y - r2.y)*(r1.y - r2.y));
}


int main() {
	PLAY();

	for (int i = 0; i < 2; i++)
		cin >> ring[i].x >> ring[i].y >> ring[i].r >> ring[i].R1;
	
	int r1 = ring[0].r;
	int r2 = ring[1].r;
	int R1 = ring[0].R1;
	int R2 = ring[1].R1;

	int res = 0;
	ld d = dist(ring[0], ring[1]);
	res += d >= r2 + R1 || d + r2 <= r1 || d + R1 <= r2;
	res += d >= r1 + R2 || d + r1 <= r2 || d + R2 <= r1;
	res += d >= R1 + R2 || d + R2 <= r1 || d + R1 <= R2;
	res += d >= R1 + R2 || d + R1 <= r2 || d + R2 <= R1;

	cout << res << endl;

	return 0;
}
