/*
Author: Ayman Salah

Category: Geometry

Idea:
- Number of cells which contain a segment of the circle = Square perimeter (8n - 4)
- The shape is symmetric and you can divide it to four small squares 
- For each cell check if it included completly in the circle or not.
- After counting them all multiply it by 4 to get the total number of cells in the big Square.
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

int solve(int n) {
	int res = 0;
	double r = n - 0.5;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			double r1 = sqrt(i*i + j*j);
			double r2 = sqrt(i*i + j*j + 2 * i + 2 * j + 2);
			res += (r1 <= r && r2 <= r);
		}
	return res * 4;
}

int main() {
	PLAY();

	int n;
	cin >> n;
	while (true) {
		cout << "In the case n = " << n << ", " << (8 * n) - 4 << " cells contain segments of the circle." << endl;
		cout << "There are " << solve(n) << " cells completely contained in the circle." << endl;
		if (cin >> n) cout << endl;
		else          break;
	}
	
	return 0;
}
