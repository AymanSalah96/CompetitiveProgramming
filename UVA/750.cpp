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

int row_vis[8];
int d1_vis[15];
int d2_vis[15];
int res[8];
int r, c;
int cur;

void backtrack(int col){
	if (col == 8) {
		printf("%2d      ", cur++);
		printf("%d", res[0] + 1);
		for (int i = 1; i < 8; i++)
			printf(" %d", res[i] + 1);
		puts("");
	}

	if (col == c) backtrack(col + 1);
	else{
		for (int i = 0; i < 8; i++) {
			if (row_vis[i] || d1_vis[col - i + 7] || d2_vis[col + i]) continue;
			row_vis[i] = d1_vis[col - i + 7] = d2_vis[col + i] = true;
			res[col] = i;
			backtrack(col + 1);
			row_vis[i] = d1_vis[col - i + 7] = d2_vis[col + i] = false;
		}
	}
}

void clear() {
	memset(row_vis, 0, sizeof row_vis);
	memset(d1_vis, 0, sizeof d1_vis);
	memset(d2_vis, 0, sizeof d2_vis);
}

int main() {
	PLAY();


	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		clear();
		scanf("%d%d", &r, &c);
		r--; c--;
		row_vis[r] = d1_vis[c - r + 7] = d2_vis[c + r] = 1;
		res[c] = r;
		cur = 1;
		if (i) puts("");
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0);
	}

	return 0;
}
