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


int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, m;
int vis[22][22];
char grid[22][22];
char l;
int cur;

bool valid(int x) { return x >= 0 && x < n; }

int fix(int y) {
	if (y < 0) return m - 1;
	if (y >= m) return 0;
	return y;
}

void flood(int x, int y) {
	vis[x][y] = 1;
	cur++;
	for (int k = 0; k < 4; k++) {
		int to_x = dx[k] + x;
		int to_y = fix(dy[k] + y);
		if (valid(to_x) && !vis[to_x][to_y] && grid[to_x][to_y] == l)
			flood(to_x, to_y);
	}

}

int main() {
	PLAY();
	
	while (cin >> n >> m) {
		
		memset(vis, 0, sizeof vis);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> grid[i][j];

		int x, y;
		cin >> x >> y;
		l = grid[x][y];
		flood(x, y);

		int res = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!vis[i][j] && grid[i][j] == l) {
					cur = 0;
					flood(i, j);
					res = max(res, cur);
				}

		cout << res << "\n";

	}

	return 0;
}
