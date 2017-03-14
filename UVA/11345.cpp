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

struct point  {
	int x, y;
};

struct rect {
	point lower_left;
	point upper_right;
};

int main() {
	PLAY();
	
	int t;
	cin >> t;
	for(int T = 1; T <= t; T++) {
		int n;
		cin >> n;
		rect r;
		int left_x = INT_MIN, right_x = INT_MAX ;
		int lower_y = INT_MIN, upper_y = INT_MAX;
		for (int i = 0; i < n; i++) {
			cin >> r.lower_left.x >> r.lower_left.y
				>> r.upper_right.x >> r.upper_right.y;
			left_x = max(left_x, r.lower_left.x);
			right_x = min(right_x, r.upper_right.x);
			lower_y = max(lower_y, r.lower_left.y);
			upper_y = min(upper_y, r.upper_right.y);
		}
		cout << "Case " << T << ": ";
		if (left_x <= right_x && lower_y <= upper_y)
			cout << (right_x - left_x) * (upper_y - lower_y) << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}
