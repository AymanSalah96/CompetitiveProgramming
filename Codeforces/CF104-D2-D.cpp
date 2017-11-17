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

char grid[1505][1505];
int n, m;
int vis[1505][1505];

int row(int x) {
	return (x + n * 1500) % n;
}
int col(int y) {
	return (y + m * 1500) % m;
}

int p[1505][1505][2];

bool solve(int i, int j) {
	int ii = row(i);
	int jj = col(j);
	if (grid[ii][jj] == '#') return false;
	if (vis[ii][jj]) {
		if (p[ii][jj][0] != i || p[ii][jj][1] != j) return true;
		return false;
	}
	vis[ii][jj] = true;
	p[ii][jj][0] = i;
	p[ii][jj][1] = j;
	bool ret = false;
	for (int k = 0; k < 4; k++)
		ret |= solve(i + dx[k], j + dy[k]);
	return ret;
}

int main() {
	PLAY();

	cin >> n >> m;
	pair<int, int> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'S') s = { i, j };
		}
	}
	memset(p, -1, sizeof p);

	if (solve(s.first, s.second))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;


	return 0;
}