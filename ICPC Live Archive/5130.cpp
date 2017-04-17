/*
Author: Ayman Salah

Category: Graphs, Flood Fill
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



char type[] = { 'W', 'A', 'K', 'J', 'S', 'D' };

const int MAXN = 1000;
int h, m;
bool grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

void clear() {
	memset(grid, 0, sizeof grid);
	memset(vis, 0, sizeof vis);
}

bool valid(int i, int j) { return i >= 0 && i < MAXN && j >= 0 && j < MAXN; }

void dfs(int i, int j) {
	stack<pair<int, int>> st;
	st.push({ i, j });
	while (sz(st)) {
		int x = st.top().first;
		int y = st.top().second;
		st.pop();
		vis[x][y] = true;
		for (int k = 0; k < 4; k++) {
			int to_i = dx[k] + x;
			int to_j = dy[k] + y;
			if (valid(to_i, to_j) && !vis[to_i][to_j] && !grid[to_i][to_j])
				st.push({ to_i, to_j });
		}
	}
}

int cnt;
void dfs2(int i, int j) {
	stack<pair<int, int>> st;
	st.push({ i, j });
	while (sz(st)) {
		int x = st.top().first;
		int y = st.top().second;
		st.pop();
		vis[x][y] = true;
		int ret = 0;
		for (int k = 0; k < 4; k++) {
			int to_i = dx[k] + x;
			int to_j = dy[k] + y;
			if (!valid(to_i, to_j) || vis[to_i][to_j]) continue;
			if (grid[to_i][to_j]) {
				st.push({ to_i, to_j });
			}
			else {
				cnt++;
				dfs(to_i, to_j);
			}
		}
	}
}

int main() {
	PLAY();


	int test = 1;
	while (cin >> h >> m && h && m) {
		cout << "Case " << test++ << ": ";
		clear();
		for (int i = 1; i <= h; i++)
			for (int j = 1, x = 1; j <= m; j++) {
				char ch; cin >> ch;
				bitset<4> bin = (isdigit(ch) ? ch - '0' : ch - 'a' + 10);
				string bin_str = bin.to_string();
				for (int j = 0; j < 4; j++)
					grid[i][x++] = bin_str[j] - '0';
			}

		dfs(0, 0);
		map<char, int> mp;
		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				if (!vis[i][j] && grid[i][j]) {
					cnt = 0;
					dfs2(i, j);
					mp[type[cnt]]++;
				}
			}
		}

		for (auto e : mp) {
			int cnt = e.second;
			while (cnt--)
				cout << e.first;
		}
		cout << endl;
	}

	return 0;
}
