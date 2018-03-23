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

const int MAX = 2e3;

vector<int> adj[MAX];
int cost[MAX], cost1[MAX];
int n, m, s, t;

bool vis[MAX];

int main() {
	PLAY();

	cin >> n >> m >> s >> t;
	while(m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<int> qu;
	fill(cost, cost + MAX, INT_MAX);
	cost[s] = 0;
	qu.push(s);
	while (sz(qu)) {
		int curnode = qu.front();
		qu.pop();
		for (auto e : adj[curnode]) {
			if (cost[e] > cost[curnode] + 1) {
				cost[e] = cost[curnode] + 1;
				qu.push(e);
			}
		}
	}
	fill(cost1, cost1 + MAX, INT_MAX);
	cost1[t] = 0;
	qu.push(t);
	while (sz(qu)) {
		int curnode = qu.front();
		qu.pop();
		for (auto e : adj[curnode]) {
			if (cost1[e] > cost1[curnode] + 1) {
				cost1[e] = cost1[curnode] + 1;
				qu.push(e);
			}
		}
	}

	ll res = 0;

	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		for (auto e : adj[i])
			vis[e] = 1;
		for (int e = i + 1; e <= n; e++) {
			if (vis[e]) continue;
			res += cost[i] + cost1[e] + 1 >= cost[t] && cost[e] + cost1[i] + 1 >= cost[t];
		}
	}
	cout << res << endl;
	
	return 0;
}
