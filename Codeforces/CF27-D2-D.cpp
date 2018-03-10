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
#define flush fflush(stdout)
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

const int MAX = 1000;
int n, m;

vector<int> adj[MAX];
stack<int> st;
pair<int, int> edges[MAX];
int idx[MAX], compID[MAX];
int assign[MAX], compHead[MAX];
int low[MAX], vis[MAX];
int T, cmp;

void dfs(int u) {
	idx[u] = low[u] = ++T;
	vis[u] = 1;
	st.push(u);
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (idx[v] == 0) dfs(v);
		if (vis[v]) low[u] = min(low[u], low[v]);
	}
	if (idx[u] == low[u]) {
		compHead[cmp] = u;
		while (true) {
			int v = st.top();
			st.pop();
			vis[v] = 0;
			compID[v] = cmp;
			if (v == u) break;
		}
		cmp++;
	}
}

int NOT(int u) {
	if (u >= m)  return u - m;
	return u + m;
}

void add(int u, int v) {
	adj[NOT(u)].push_back(v);
	adj[NOT(v)].push_back(u);
}

int main() {
	PLAY();

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		if (u > v) swap(u, v);
		edges[i] = { u, v };
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) continue;
			if (edges[i].first < edges[j].first
				&& edges[i].second > edges[j].first
				&& edges[i].second < edges[j].second) {
				add(i, j);
				add(NOT(i), NOT(j));
			}
		}
	}

	for (int i = 0; i < 2 * m; i++) {
		if (idx[i] == 0)
			dfs(i);
	}
	for (int i = 0; i < m; i++)
		if (compID[i] == compID[NOT(i)]) {
			cout << "Impossible" << endl;
			return 0;
		}
	
	memset(assign, -1, sizeof assign);

	for (int i = 0; i < cmp; i++) {
		if (assign[i] == -1) {
			assign[i] = 1;
			assign[compID[NOT(compHead[i])]] = 0;
		}
	}
	
	for (int i = 0; i < m; i++)
		if (assign[compID[i]]) cout << "o";
		else cout << "i";

	return 0;
}
