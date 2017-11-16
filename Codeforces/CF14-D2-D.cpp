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

vector<vector<int>> adj;
int vis[500];
int n;

vector<int> comp;

void dfs(int node) {
	if (vis[node]) return;
	vis[node] = true;
	comp.push_back(node);
	for (int i = 0; i < sz(adj[node]); i++)
		dfs(adj[node][i]);
}

int getMaxPath(int node) {
	vis[node] = true;
	int ret = 0;
	for (int i = 0; i < sz(adj[node]); i++) {
		if (vis[adj[node][i]]) continue;
		ret = max(ret, 1 + getMaxPath(adj[node][i]));
	}
	return ret;
}

int solve() {
	vector<int> comp1, comp2;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			comp.clear();
			dfs(i);
			if (sz(comp1)) comp2 = comp;
			else comp1 = comp;
		}
	}
	int mx1 = 0, mx2 = 0;
	for (int i = 0; i < sz(comp1); i++) {
		memset(vis, 0, sizeof vis);
		mx1 = max(mx1, getMaxPath(comp1[i]));
	}
	for (int i = 0; i < sz(comp2); i++) {
		memset(vis, 0, sizeof vis);
		mx2 = max(mx2, getMaxPath(comp2[i]));
	}
	return mx1 * mx2;
}

int main() {
	PLAY();

	cin >> n;
	vector<pair<int, int>> edges(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> edges[i].first >> edges[i].second;
		edges[i].first--;
		edges[i].second--;
	}

	int res = INT_MIN;

	for (int i = 0; i < n - 1; i++) {
		adj.clear();
		adj.resize(n);
		memset(vis, 0, sizeof vis);
		for (int j = 0; j < n - 1; j++) {
			if (i == j) continue;
			adj[edges[j].first].push_back(edges[j].second);
			adj[edges[j].second].push_back(edges[j].first);
		}
		res = max(res, solve());
	}
	cout << res << endl;

	return 0;
}