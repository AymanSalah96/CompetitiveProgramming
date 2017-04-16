/*
Author: Ayman Salah

Category: Brute Force, Implementation 
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
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}



struct rgb {
	int r, g, b;
};
double dist(rgb a1, rgb a2) {
	return sqrt((a1.r - a2.r)*(a1.r - a2.r) + (a1.g - a2.g)*(a1.g - a2.g) + (a1.b - a2.b)*(a1.b - a2.b));
}
int main() {
	PLAY();

	
	vector<pair<int, pair<int, int>>> v;
	for (int i = 0; i < 16; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(a, make_pair(b, c)));
	}
	vector<pair<int, pair<int, int>>> m;

	int a, b, c;
	while (cin >> a >> b >> c) {
		if (a == -1 && b == -1 && c == -1) break;
		m.push_back(make_pair(a, make_pair(b, c)));
	}
	for (int i = 0; i < sz(m); i++) {
		rgb r1 = { m[i].first, m[i].second.first, m[i].second.second };
		double mn = INT_MAX;
		rgb r2;
		for (int j = 0; j < sz(v); j++) {
			rgb tmp = { v[j].first, v[j].second.first, v[j].second.second };
			double d = dist(r1, tmp);
			if (d < mn) {
				mn = d;
				r2 = tmp;
			}
		}
		cout << "(" << r1.r << "," << r1.g << "," << r1.b << ")" << " maps to (" << r2.r << "," << r2.g << "," << r2.b << ")" << endl;
	}
	return 0;
}
