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
#include <assert.h>
using namespace std;

#define PI 3.14159265359
#define all(v) v.begin(),v.end()
#define sortva(v) sort(all(v))
#define sortvd(v) sort(v.rbegin(),v.rend())
#define sortaa(first,n) sort(first,first+n)
#define sortad(first,n) sort(first,first+n),reverse(first,first+n)
#define sfi1(v) scanf("%dist",&v)
#define sfi2(v1,v2) scanf("%dist %dist",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%dist %dist %dist",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define sfstr(v) scanf("%sum", v);
#define sz(v) (int)v.size()
#define ndl puts("")
#define flush fflush(stdout)
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll first, ll second) { return !second ? first : gcd(second, first % second); }
ll lcm(ll first, ll second) { return (first / gcd(first, second)) * second; }

void PLAY() {
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int MAX = 2e5 + 10;
const int MAXLOG = 20;

vector<int> adj[MAX]; 
int table[MAX][MAXLOG], depth[MAX];

void dfs(int u, int p) {
	table[u][0] = p;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		depth[v] = depth[u] + 1;
		dfs(v, u);
	}
}

int LCA(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);
	for (int k = MAXLOG - 1; k >= 0; k--)
		if (depth[u] - (1 << k) >= depth[v])
			u = table[u][k];
	if (u == v) return u;
	for (int k = MAXLOG- 1; k >= 0; k--) {
		if (table[u][k] != table[v][k]) {
			u = table[u][k];
			v = table[v][k];
		}
	}
	return table[u][0];
}

int length(int u, int v) {
	return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
}

int main() {
	PLAY();

	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(table, -1, sizeof table);
	dfs(0, -1);

	for (int k = 1; k < MAXLOG; k++) {
		for (int u = 0; u < n; u++) {
			if (table[u][k - 1] == -1) continue;
			table[u][k] = table[table[u][k - 1]][k - 1];
		}
	}

	
	ll res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 2 * i; j <= n; j += i)
			res += length(i - 1, j - 1) + 1;

	cout << res << endl;

	return 0;
}
