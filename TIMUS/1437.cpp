/*
Author: Ayman Salah

Category: DP

Idea:
- My approach is to use dynamic programming to solve this problem.
- DP states is (a,b,c) - current capacity in each can.
- DP transitions is filling each can to the maximum capacity,
- Then pick every two cans (x,y) and pour from x to y and vice versa.
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

int res = 0, max_a, max_b, max_c;
bool vis[300][300][300];

set<int> st;

void get(int a, int b, int c) {
	for (int i = 1; i < (1 << 3); i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			if (i & (1 << j)) {
				if (j == 0) sum += a;
				else if (j == 1) sum += b;
				else sum += c;
			}
		}
		st.insert(sum);
	}
}

void solve(int a, int b, int c) {
	if (a > max_a || b > max_b || c > max_c || vis[a][b][c]) return;
	vis[a][b][c] = true;
	get(a, b, c);
	solve(max_a, b, c);
	solve(a, max_b, c);
	solve(a, b, max_c);
	solve(a + min(max_a - a, b), b - min(max_a - a, b), c);
	solve(a - min(a, max_b - b), b + min(a, max_b - b), c);
	solve(a + min(max_a - a, c), b, c - min(max_a - a, c));
	solve(a - min(a, max_c - c), b, c + min(a, max_c - c));
	solve(a, b + min(max_b - b, c), c - min(max_b - b, c));
	solve(a, b - min(b, max_c - c), c + min(b, max_c - c));
}

int main() {
	PLAY();
	cin >> max_a >> max_b >> max_c;
	solve(0, 0, 0);
	cout << sz(st) - bool(st.find(0) != st.end()) << endl;

	return 0;
}
