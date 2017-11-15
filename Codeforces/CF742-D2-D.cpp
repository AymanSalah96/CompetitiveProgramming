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


int w[1005], b[1005];
int dp[5005][1005];
int vis[1005];
int max_w;

vector<int> adj[1005];
vector<vector<pair<int, int>>> comp2;
vector<vector<int>> comp;
vector<int> tmpComp;

void dfs(int node) {
	if (vis[node]) return;
	vis[node] = true;
	tmpComp.push_back(node);
	for (int i = 0; i < sz(adj[node]); i++)
		dfs(adj[node][i]);
}


int solve(int comp_i, int cur_w) {
	if (comp_i == sz(comp2)) return 0;
	int &ret = dp[comp_i][cur_w];
	if (ret != -1) return ret;
	ret = solve(comp_i + 1, cur_w);
	for (int j = 0; j < sz(comp2[comp_i]); j++) {
		if (cur_w + comp2[comp_i][j].first <= max_w)
			ret = max(ret, comp2[comp_i][j].second +
				solve(comp_i + 1, cur_w + comp2[comp_i][j].first));
	}
	return ret;
}

int main() {
	PLAY();

	int n, m;
	cin >> n >> m >> max_w;
	for (int i = 0; i < n; i++)
		cin >> w[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	while (m--) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			tmpComp.clear();
			dfs(i);
			comp.push_back(tmpComp);
		}
	}
	comp2.resize(sz(comp));
	for (int i = 0; i < sz(comp); i++) {
		int total_w = 0;
		int total_b = 0;
		for (int j = 0; j < sz(comp[i]); j++) {
			total_w += w[comp[i][j]];
			total_b += b[comp[i][j]];
			comp2[i].push_back({ w[comp[i][j]], b[comp[i][j]] });
		}
		if (total_w <= max_w)
			comp2[i].push_back({ total_w, total_b });
	}
	
	memset(dp, -1, sizeof dp);
	cout << solve(0, 0) << endl;


	return 0;
}