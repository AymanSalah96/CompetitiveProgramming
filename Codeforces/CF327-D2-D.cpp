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
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
}


int n, m;
char grid[505][505];
bool vis[505][505];

bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }

void dfs(int i, int j, int forbx, int forby) {
	if (vis[i][j]) return;
	vis[i][j] = true;
	for (int k = 0; k < 4; k++)
		if (valid(i + dx[k], j + dy[k]) && !vis[i + dx[k]][j + dy[k]] && grid[i + dx[k]][j + dy[k]] == 'B')
			dfs(i + dx[k], j + dy[k], forbx, forby);
	if (i != forbx || j != forby) {
		printf("D %d %d\n", i + 1, j + 1);
		printf("R %d %d\n", i + 1, j + 1);
	}
}

void tmpDfsToCount(int i, int j) {
	if (vis[i][j]) return;
	vis[i][j] = true;
	for (int k = 0; k < 4; k++)
		if (valid(i + dx[k], j + dy[k]) && !vis[i + dx[k]][j + dy[k]] && grid[i + dx[k]][j + dy[k]] == 'B')
			tmpDfsToCount(i + dx[k], j + dy[k]);
}

int main() {
	PLAY();

	sfi2(n, m);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] != '#') {
				grid[i][j] = 'B';
				cnt++;
			}
		}
	}
	int compCnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == 'B' && !vis[i][j])
				tmpDfsToCount(i, j), compCnt++;

	printf("%d\n", cnt + (cnt - compCnt) * 2);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == 'B')
				printf("B %d %d\n", i + 1, j + 1);

	memset(vis, 0, sizeof vis);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!vis[i][j] && grid[i][j] == 'B')
				dfs(i, j, i, j);

	return 0;
}
